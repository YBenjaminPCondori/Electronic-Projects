const http = require('http');
const fs = require('fs');
const path = require('path');

let items = ['First Item'];

function handleRequest(req, res) {
  const { method, url } = req;
  if (url === '/api/items') {
    if (method === 'GET') {
      res.writeHead(200, { 'Content-Type': 'application/json' });
      res.end(JSON.stringify(items));
    } else if (method === 'POST') {
      let body = '';
      req.on('data', chunk => body += chunk);
      req.on('end', () => {
        try {
          const { item } = JSON.parse(body);
          if (item) items.push(item);
          res.writeHead(200, { 'Content-Type': 'application/json' });
          res.end(JSON.stringify(items));
        } catch (e) {
          res.writeHead(400);
          res.end();
        }
      });
    } else {
      res.writeHead(405);
      res.end();
    }
  } else {
    const filePath = path.join(__dirname, 'public', url === '/' ? 'index.html' : url);
    fs.readFile(filePath, (err, content) => {
      if (err) {
        res.writeHead(404);
        res.end('Not found');
      } else {
        const ext = path.extname(filePath);
        let contentType = 'text/html';
        if (ext === '.js') contentType = 'text/javascript';
        else if (ext === '.css') contentType = 'text/css';
        res.writeHead(200, { 'Content-Type': contentType });
        res.end(content);
      }
    });
  }
}

const server = http.createServer(handleRequest);
const PORT = process.env.PORT || 3000;
server.listen(PORT, () => console.log(`Server running on port ${PORT}`));
