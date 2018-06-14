const http = require('http');
const bl = require('bl');

let urls = process.argv.slice(2);
let dataMap = new Map();

for (let i = 0; i < urls.length; ++i) {
    http.get(urls[i], (response) => {
        response.pipe(bl((err, data) => {
            if (err) {
                console.log(err);
            }
            callBack(i, data);
        }));
        response.on('error', console.error);
    }).on('error', console.error);
}

let callBack = function(i, data) {
    dataMap.set(i, data.toString());
    if (dataMap.size >= 3) {
        print();
    }
};

let print = function() {
    for (let i = 0; i < dataMap.size; ++i) {
        console.log(dataMap.get(i));
    }
};

