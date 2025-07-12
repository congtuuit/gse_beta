/* Globaldizajn MooMarquee - marquee replacement 2008-06-04 */

var MooMarquee = new Class({
	options: {
		direction: 'vertical', //'vertical', //horizontal
		speed: 50,
		width: 150,
		height: 150,
		step: 1
	},

	initialize: function(el, options) {
		this.setOptions(options);
		this.element = el;
		this.periodical = "";

		this.newDiv = new Element("div");

		if(this.options.direction!="vertical"){
			this.newDiv.setStyles({
				"white-space":"nowrap",
				position:"absolute"
			})
		}

		this.element.setStyles({
			width : this.options.width,
			height: this.options.height,
			overflow:"hidden",
			position:"absolute"
		})
		this.newDiv.innerHTML = this.element.innerHTML;

		this.element.innerHTML = "";
		this.newDiv.injectInside(this.element);

		this.newDiv.addEvents({

			"mouseover" : function() {
				$clear(this.periodical)
			}.bind(this),
			"mouseout"  : function() {

				this.periodical = this.anim.bind(this).periodical(this.options.speed)

			}.bind(this)

		})
		
		this.marqueeSize = this.options.direction=="vertical" ? this.newDiv.getSize().size.y*-1 : this.newDiv.getSize().size.x*-1;
		this.limit = this.options.direction=="vertical" ? this.element.getSize().size.y : this.element.getSize().size.x;
		this.position = this.limit;

		this.style = this.options.direction=="vertical" ? "marginTop" : "left";

		this.periodical = this.anim.bind(this).periodical(this.options.speed);

	},
	anim: function() {

		if(this.position<this.marqueeSize) this.position = this.limit;
		this.position = this.position-this.options.step;
		this.newDiv.setStyle(this.style,this.position);
		//this.newDiv.style[this.style] = this.position+"px";

	}

})
MooMarquee.implement(new Options, new Events);
