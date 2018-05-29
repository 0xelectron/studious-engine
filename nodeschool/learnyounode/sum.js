/* parse all elements to integers and filter out invalid integers (Nan) */
var arr = process.argv.slice(2,).map((x) => parseInt(x)).filter(Boolean);
/* sum */
console.log(arr.reduce((accumulater, x) => accumulater += x));