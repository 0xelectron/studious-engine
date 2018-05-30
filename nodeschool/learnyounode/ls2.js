const ls = require('./lsmodule.js');

ls(process.argv[2], process.argv[3], (err, fileNames) => {
    if (err) {
        return console.error(err);
    }
    for (let item of fileNames) {
        console.log(item);
    }
});
