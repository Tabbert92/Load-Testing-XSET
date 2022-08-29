Action()
{

	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	web_set_sockets_option("SSL_VERSION", "AUTO");
	

	lr_start_transaction("login");

	web_submit_form("login.pl", 
		"Snapshot=t2.inf", 
		ITEMDATA, 
		"Name=username", "Value=jojo", ENDITEM, 
		"Name=password", "Value=bean", ENDITEM, 
		"Name=login.x", "Value=74", ENDITEM, 
		"Name=login.y", "Value=11", ENDITEM, 
		LAST);

	lr_end_transaction("login",LR_AUTO);


	lr_start_transaction("ItineraryListBrowsing");

	web_image("Itinerary Button", 
		"Alt=Itinerary Button", 
		"Snapshot=t3.inf", 
		LAST);

	lr_end_transaction("ItineraryListBrowsing",LR_AUTO);


	lr_start_transaction("ItineraryListCanceling");

	web_submit_form("itinerary.pl", 
		"Snapshot=t4.inf", 
		ITEMDATA, 
		"Name=1", "Value=<OFF>", ENDITEM, 
		"Name=removeAllFlights.x", "Value=52", ENDITEM, 
		"Name=removeAllFlights.y", "Value=11", ENDITEM, 
		LAST);

	lr_end_transaction("ItineraryListCanceling",LR_AUTO);


	lr_start_transaction("logout");

	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Snapshot=t5.inf", 
		LAST);

	lr_end_transaction("logout",LR_AUTO);

	return 0;
}