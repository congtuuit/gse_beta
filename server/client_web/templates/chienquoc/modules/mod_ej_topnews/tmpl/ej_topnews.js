
var ejnewsClass = new Class({
	
	initialize: function(setname) {
		
		var tabs 	 = $$('a[id^='+setname+']');
		var contents = $$('div[id^='+setname+']');
		//alert(tabs.length);
		
		
		tabs.each(function(tab) {
			tab.addEvent('click', function() {
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