function getIEVersion()
{
	var strBrowserName = navigator.appName;
	var strBrowserAgent = navigator.userAgent;
	var strBrowserVersion = navigator.appVersion;

	var MsIEOffset	=	strBrowserAgent.toLowerCase().indexOf('msie ');
	if (MsIEOffset == -1)
	{
		return	0;
	}
	else
	{	
		return	parseFloat(strBrowserAgent.substring(MsIEOffset + 5, strBrowserAgent.indexOf(';', MsIEOffset)));
	}
}

function getViewportSize()
{
	var viewportwidth;
	var viewportheight;
	 
	// the more standards compliant browsers (mozilla/netscape/opera/IE7) use window.innerWidth and window.innerHeight
	 
	if (typeof window.innerWidth != 'undefined')
	{
		viewportwidth = window.innerWidth,
		viewportheight = window.innerHeight
	}
	 
	// IE6 in standards compliant mode (i.e. with a valid doctype as the first line in the document)

	else if (typeof document.documentElement != 'undefined'
		&& typeof document.documentElement.clientWidth !=
		'undefined' && document.documentElement.clientWidth != 0)
	{
		viewportwidth = document.documentElement.clientWidth,
		viewportheight = document.documentElement.clientHeight
	}
	 
	// older versions of IE
	else
	{
		viewportwidth = document.getElementsByTagName('body')[0].clientWidth,
		viewportheight = document.getElementsByTagName('body')[0].clientHeight
	}
	return [viewportwidth, viewportheight];
}	