const fs = require('fs');

fs.readFile(process.argv[2], 'utf8',
    (err, data) => {
        if (!err) {
            /*  last line doesn't contain '\n'  */
            console.log(data.split('\n').length - 1);
        }
    });
