let http = require("http"),
    url = require("url");

let server = http.createServer((req, res)=>{
    let pathname = url.parse(req.url).pathname;

    if(pathname == "/update/version.txt"){
	res.write("v1.0.0.9");
        res.end();
	return ;
    }

    if(pathname == "/activate/index.php"){
	res.end("<p/>Activate Successful!<p/>");
	return ;
    }

    res.write("404");
    res.send();
    return ;
}).listen(80)
