const fs = require('fs');
const path = require('path');

fs.readdir(process.argv[2], (err, list) => {
    let ext = '.' + process.argv[3];
    let lists = list.filter((item) => {
        return path.extname(item) == ext;
    });
    for (let file of lists) {
        console.log(file);
    }
});
