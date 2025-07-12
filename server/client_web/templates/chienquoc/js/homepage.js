// JavaScript Document
window.addEvent("domready", function(){
		new MooMarquee($("listitem"),{direction:'horizontal',speed:20,width:550,height:50})
		$('camvequan').addEvent('mouseenter', function(){
						$('character').setStyle('background', 'url(./templates/chienquoc/images/intro_camvequan.gif)');
					
		});
		$('maoson').addEvent('mouseenter', function(){
						$('character').setStyle('background', 'url(./templates/chienquoc/images/intro_maoson.gif)');
		});
		$('thucson').addEvent('mouseenter', function(){
						$('character').setStyle('background', 'url(./templates/chienquoc/images/intro_thucson.gif)');
		});
		$('duongmon').addEvent('mouseenter', function(){
						$('character').setStyle('background', 'url(./templates/chienquoc/images/intro_duongmon.gif)');
		});
		$('conluan').addEvent('mouseenter', function(){
						$('character').setStyle('background', 'url(./templates/chienquoc/images/intro_conluan.gif)');
		});
		$('vanmongcoc').addEvent('mouseenter', function(){
						$('character').setStyle('background', 'url(./templates/chienquoc/images/intro_vanmongcoc.gif)');
		});
		$('daohoanguyen').addEvent('mouseenter', function(){
						$('character').setStyle('background', 'url(./templates/chienquoc/images/intro_daohoanguyen.gif)');
		});
		
		
		var movethumbs = new Fx.Styles('showbox', {duration: 2000, transition: Fx.Transitions.quadOut});
		$('chu').addEvent('click', function(e){
				var topvalue = $('showbox').getStyle("top");
				//alert(topvalue);
				movethumbs.custom({ top: [topvalue, -0]});
			});
		$('han').addEvent('click', function(e){
				var topvalue = $('showbox').getStyle("top");
				//alert(topvalue);
				movethumbs.custom({ top: [topvalue, -170]});
			});
		$('te').addEvent('click', function(e){
				var topvalue = $('showbox').getStyle("top");
				//alert(topvalue);
				movethumbs.custom({ top: [topvalue, -335]});
			});
		$('so').addEvent('click', function(e){
				var topvalue = $('showbox').getStyle("top");
				//alert(topvalue);
				movethumbs.custom({ top: [topvalue, -505]});
			});
		$('yen').addEvent('click', function(e){
				var topvalue = $('showbox').getStyle("top");
				//alert(topvalue);
				movethumbs.custom({ top: [topvalue, -670]});
			});
		$('trieu').addEvent('click', function(e){
				var topvalue = $('showbox').getStyle("top");
				//alert(topvalue);
				movethumbs.custom({ top: [topvalue, -835]});
			});
		$('nguy').addEvent('click', function(e){
				var topvalue = $('showbox').getStyle("top");
				//alert(topvalue);
				movethumbs.custom({ top: [topvalue, -1005]});
			});
		$('tan').addEvent('click', function(e){
				var topvalue = $('showbox').getStyle("top");
				//alert(topvalue);
				movethumbs.custom({ top: [topvalue, -1170]});
			});
		
		
	})