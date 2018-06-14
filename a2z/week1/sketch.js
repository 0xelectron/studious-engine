function setup() {
    let c = createCanvas(200, 200);
    let highlight = eventHandler(c, '#AAA');
    let unhighlight = eventHandler(c);
    c.style('border-style', 'dashed');
    c.style('font-size', '36pt');
    c.style('padding', '24px');
    c.style('width', '50%');
    c.text('drag files here');

    c.dragOver(highlight);
    c.dragLeave(unhighlight);
    c.drop(gotFile, unhighlight);
}

function gotFile(file) {
    let div = createDiv();

    let fileInfo = createP(`${file.name} ${file.type} ${file.size} bytes\n`);
    fileInfo.parent(div);

    let data;
    if (file.type === 'image') {
       data = createImg(file.data);
    } else if (file.type === 'text') {
        data = createP(findFelchIndex(file.data));
    }
    data.parent(div);
}

function eventHandler(element, color = '') {
    function highligher() {
        element.style('background', color);
    }
    return highligher;
}

function findFelchIndex(data) {
    // felch index formulae constants
    let f1 = 206.835;
    let f2 = 84.6;
    let f3 = 1.015;
    let r1;
    let r2;
    let felch;

    let report;
    let totalSyllables = 0;
    let totalWords = 0;
    let totalSentences = 0;

    let delimiters = '.:;?! !@#$%^&*()]+';
    let sentenceDelimiters = '.:;?!';

    let words = splitTokens(data, delimiters);
    let sentences = splitTokens(data, sentenceDelimiters);

    words.forEach((word) => {
        totalSyllables += countSyllables(word);
        totalWords++;
    });

    totalSentences = sentences.length;

    r1 = totalSyllables / totalWords;
    r2 = totalWords / totalSentences;

    felch = f1 - (f2 * r1) - (f3 * r2);

    report = `
    Total Syllables : ${ totalSyllables } \n
    Total Words     : ${ totalWords }     \n
    Total Sentences : ${ totalSentences } \n
    Felch Index     : ${ felch }          \n`;

    return report;
}

function countSyllables(word) {
    let count = 0;
    let len = word.length;
    let vowels = 'aeiouAEIOU';
    let i;
    let j;
    let k;

    for (i = 0; i < len; ++i) {
        j = vowels.indexOf(word[i]);
        if (i == len -1) {
            if (j >= 0 && word[i] !== 'e'&& word[i] !== 'E') {
                count++;
            }
        } else {
            k = vowels.indexOf(word[i+1]);
            if (j >= 0 && k < 0) {
                count++;
            }
        }
    }
    return count;
}
