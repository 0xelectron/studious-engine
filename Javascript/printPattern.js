let printPattern = function(n) {
    let i;
    let j;
    let k;
    let l;
    let str;

    for (i = n; i >= 1; --i) {
        str = '';
        k = ((i % n) == 0) ? n : (i % n);
        l = n - k;
        for (j = 0; j < k; ++j) {
            str += ' * ';
        }
        for (j = 0; j < (l * 2); ++j) {
            str += '   ';
        }
        for (j = 0; j < k; ++j) {
            str += ' * ';
        }
        console.log(str);
    }
    for (i = 1; i <= n; ++i) {
        str = '';
        k = ((i % n) == 0) ? n : (i % n);
        l = n - k;
        for (j = 0; j < k; ++j) {
            str += ' * ';
        }
        for (j = 0; j < (l * 2); ++j) {
            str += '   ';
        }
        for (j = 0; j < k; ++j) {
            str += ' * ';
        }
        console.log(str);
    }
}

n = 5
printPattern(5);
