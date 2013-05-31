require(['emd'], function(emd) {
	
	var print = function(text) {
		var body = document.getElementsByTagName('body').item(0);
		var child = document.createElement('p');
		child.appendChild(document.createTextNode(text));
		body.appendChild(child);
	};
	
	print(emd([1,0,0,0], [1,0,0,0]));
	print(emd([1,0,0,0], [1,1,0,0]));
	print(emd([1,0,0,0], [1,1,2,3]));
	print(emd([1,3,2,1], [1,0,0,0]));
	print(emd([0.5,0,0,0,0.5,1,1,1], [1,0,0,0]));
	print(emd([1,0,0,0], [0.5,0,0,0]));
	
});