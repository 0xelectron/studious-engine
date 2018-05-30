const http = require('http');
const bl = require('bl');

let url = process.argv[2];

http.get(url, (response) => {
    response.pipe(bl((err, data) => {
        if (err) {
            console.error(err);
        }
        console.log(data.toString());
    }));
    response.on('error', console.error);
}).on('error', console.error);
