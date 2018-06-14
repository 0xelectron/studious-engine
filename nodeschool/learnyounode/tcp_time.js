const net = require('net');

let server = net.createServer((socket) => {
    let dt = new Date();
    let dtStr = `${dt.getFullYear()}-${dt.getMonth()}-${dt.getDate()} ${dt.getHours()}:${dt.getMinutes()}`;
    socket.end(dtStr);
});

server.listen(process.argv[2]);


