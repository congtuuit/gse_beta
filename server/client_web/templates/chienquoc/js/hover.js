document.imageOut = new Object();
document.imageOver = new Object();
//
function initImages() {	
	// PNG Fix for IE<7
	var png_fix = "./images/spacer.gif";
	var pngRegExp = new RegExp("\\.png$", "i");
	var f = "DXImageTransform.Microsoft.AlphaImageLoader";
	//
	var imageArray = $$("img", "input");
	imageArray.each(function(item){
		var image = item.src.substr(item.src.lastIndexOf("/")+1);
		var id = item.id || image.replace("_n.", "").replace("_N.", "");
		var hover = (image.toLowerCase().lastIndexOf("_n.") != -1);
		//
		if (hover && document.imageOut && document.imageOver) {
			document.imageOut[id] = new Image();
			document.imageOut[id].src = item.src;
			document.imageOver[id] = new Image();
			document.imageOver[id].src = item.src.substr(0, item.src.lastIndexOf("/")+1)+image.replace("_n.", "_o.").replace("_N.", "_O.");
		};
		// PNG Fix for IE<7
		if (window.ie && !window.ie7 && image.test(pngRegExp)) {
			item.style.width = item.offsetWidth+"px";
			item.style.height = item.offsetHeight+"px";
			item.style.filter = "progid:"+f+"(src='"+item.src+"', sizingMethod='scale');";
			item.src = png_fix;
		};
		//
		if (hover && document.imageOut && document.imageOver) {
			item.addEvent("mouseover", function(e){
				if (document.imageOver && document.imageOver[this.id]) setImage(this, document.imageOver[this.id].src);
			});
			item.addEvent("mouseout", function(){
				if (document.imageOut && document.imageOut[this.id]) setImage(this, document.imageOut[this.id].src);
			});
			item.id = id;
		};
	});
	//
	function setImage(imageObject, src) {
		if (window.ie && !window.ie7) {
			if (imageObject.filters[f] && imageObject.filters[f].src.test(pngRegExp)) {
				imageObject.filters[f].src = src;
			} else {
				imageObject.src = src;
			};
		} else {
			imageObject.src = src;
		};
	};
	/////////////////////////////////////////////////////////////////////
	
	
	
	
	
	
	
};
//
window.addEvent("load", function(){
	initImages();
});





