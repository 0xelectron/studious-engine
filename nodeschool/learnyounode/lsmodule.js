const fs = require('fs');
const path = require('path');

module.exports = function(dirName, ext, callback) {
    fs.readdir(dirName, (err, fileNames) => {
        let extension = '.' + ext;
        if (err) {
            return callback(err);
        }
        let fileNamesFiltered = fileNames.filter((item) => {
            return path.extname(item) == extension;
        });
        callback(null, fileNamesFiltered);
    });
};
