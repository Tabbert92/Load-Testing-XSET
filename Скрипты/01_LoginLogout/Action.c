Action()
{

	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		LAST);

	web_set_sockets_option("SSL_VERSION", "AUTO");
	

	lr_start_transaction("login");

	web_submit_form("login.pl", 
		"Snapshot=t19.inf", 
		ITEMDATA, 
		"Name=username", "Value=jojo", ENDITEM, 
		"Name=password", "Value=bean", ENDITEM, 
		"Name=login.x", "Value=47", ENDITEM, 
		"Name=login.y", "Value=3", ENDITEM, 
		LAST);

	lr_end_transaction("login",LR_AUTO);


	lr_start_transaction("logout");

	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Snapshot=t20.inf", 
		LAST);

	lr_end_transaction("logout",LR_AUTO);

	return 0;
}