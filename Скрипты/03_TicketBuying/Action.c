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

	web_set_sockets_option("SSL_VERSION", "AUTO");

	
	lr_start_transaction("login");

	web_submit_form("login.pl", 
		"Snapshot=t4.inf", 
		ITEMDATA, 
		"Name=username", "Value=jojo", ENDITEM, 
		"Name=password", "Value=bean", ENDITEM, 
		"Name=login.x", "Value=62", ENDITEM, 
		"Name=login.y", "Value=6", ENDITEM, 
		LAST);

	lr_end_transaction("login",LR_AUTO);
	

	lr_start_transaction("ticketSearch");

	web_image("Search Flights Button", 
		"Alt=Search Flights Button", 
		"Snapshot=t5.inf", 
		LAST);

	web_submit_form("reservations.pl", 
		"Snapshot=t6.inf", 
		ITEMDATA, 
		"Name=depart", "Value=Denver", ENDITEM, 
		"Name=departDate", "Value=08/30/2022", ENDITEM, 
		"Name=arrive", "Value=Frankfurt", ENDITEM, 
		"Name=returnDate", "Value=08/31/2022", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=roundtrip", "Value=<OFF>", ENDITEM, 
		"Name=seatPref", "Value=Window", ENDITEM, 
		"Name=seatType", "Value=First", ENDITEM, 
		"Name=findFlights.x", "Value=50", ENDITEM, 
		"Name=findFlights.y", "Value=7", ENDITEM, 
		LAST);

	web_submit_form("reservations.pl_2", 
		"Snapshot=t7.inf", 
		ITEMDATA, 
		"Name=outboundFlight", "Value=010;723;08/30/2022", ENDITEM, 
		"Name=reserveFlights.x", "Value=61", ENDITEM, 
		"Name=reserveFlights.y", "Value=10", ENDITEM, 
		LAST);
	
	lr_end_transaction("ticketSearch",LR_AUTO);
	
	
	lr_start_transaction("ticketBuying");

	web_submit_form("reservations.pl_3", 
		"Snapshot=t8.inf", 
		ITEMDATA, 
		"Name=firstName", "Value=Jojo", ENDITEM, 
		"Name=lastName", "Value=Bean", ENDITEM, 
		"Name=address1", "Value=", ENDITEM, 
		"Name=address2", "Value=", ENDITEM, 
		"Name=pass1", "Value=Jojo Bean", ENDITEM, 
		"Name=creditCard", "Value=4200 0000 0000 0000", ENDITEM, 
		"Name=expDate", "Value=08/25", ENDITEM, 
		"Name=saveCC", "Value=<OFF>", ENDITEM, 
		"Name=buyFlights.x", "Value=34", ENDITEM, 
		"Name=buyFlights.y", "Value=9", ENDITEM, 
		LAST);

	lr_end_transaction("ticketBuying",LR_AUTO);


	lr_start_transaction("logout");

	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Snapshot=t9.inf", 
		LAST);

	lr_end_transaction("logout",LR_AUTO);

	return 0;
}