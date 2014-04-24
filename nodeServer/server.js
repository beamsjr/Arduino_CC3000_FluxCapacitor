var request = require('request');
var cheerio = require('cheerio');
var url = 'http://hackaday.io/project/594-Wireless-Flux-Capacitor';
var fc = 'http://192.168.1.98/delay/';
var prevLikes = 0;


console.log("Starting");
req();
function req() {
	setTimeout(function(){
    request(url, function(err, resp, body) {
        if (err)
            throw err;
        $ = cheerio.load(body);
        var likes = $('#like_count').text();
        if(likes != prevLikes){
        	var delay = 300 - parseInt(likes, 10);
        	console.log(delay);
        	prevLikes = likes;
        	setDelay(delay);
        };
    });
    req();
	}, 900000);
}

function setDelay(delay){
	 request(fc + delay, function(err, resp, body) {
	 	console.log(body);
	 });
}