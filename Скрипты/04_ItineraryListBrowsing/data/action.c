Action()
{

	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(8);

	web_submit_form("login.pl", 
		"Snapshot=t4.inf", 
		ITEMDATA, 
		"Name=username", "Value=jojo", ENDITEM, 
		"Name=password", "Value=bean", ENDITEM, 
		"Name=login.x", "Value=41", ENDITEM, 
		"Name=login.y", "Value=9", ENDITEM, 
		LAST);

	lr_think_time(23);

	lr_start_transaction("ItineraryBrowsing");

	web_image("Itinerary Button", 
		"Alt=Itinerary Button", 
		"Snapshot=t5.inf", 
		LAST);

	web_set_sockets_option("SSL_VERSION", "AUTO");

	lr_end_transaction("ItineraryBrowsing",LR_AUTO);

	lr_start_transaction("logout");

	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Snapshot=t6.inf", 
		LAST);

	lr_end_transaction("logout",LR_AUTO);

	return 0;
}