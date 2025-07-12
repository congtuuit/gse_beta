// JavaScript Document
var ejTabClass = new Class({
	
	initialize: function(ejname) {
		
		var tabs 	 = $$('li[class^='+ejname+'tab]');
		var contents = $$('div[class^='+ejname+'content]');
		tabs.each(function(tab) {
			tab.addEvent('click', function() {
					$('homepagenews').addClass('hide');
					$('homepagenews').removeClass('active');
					for(i=0;i<tabs.length;i++){
						if(tabs[i] == this ){
							tabs[i].addClass('active');
							
							contents[i].addClass('active');
						}else{
							tabs[i].removeClass('active');
							
							contents[i].removeClass('active');
						}
					}
			});
		});
		
	}
});  

//////////////////////////////////////////////////////////////////////////////////////////////
//
// $$('a.external'); // => Array of links with class 'external'  
// $$('a[href=#]‘); // => Array of links with href=”#”  
// $$(’form input[disabled]‘); // Array of input elements inside a form with a disabled attribute  
// $$(’form input[disabled=disabled]‘); // Array of disabled input elements inside a form (valid XHTML)  
// $$(’div[class^=foo]‘); // => Array of divs with classname starting with ‘foo’  
// $$(’[class$=bar]‘); // => Array of elements with classname ending with ‘bar’  
// $$(’*[class$=bar]‘); // => Returns the same as the previous selector
//
//////////////////////////////////////////////////////////////////////////////////////////////