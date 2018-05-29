const fs = require('fs');

const file = fs.readFileSync(process.argv[2]);
/*  No new line at the end of last line. */
console.log(file.toString('utf8').split('\n').length - 1);
