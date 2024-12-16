<?php namespace ProcessWire;

//* Breakpoints */

	$mQueryMob = "640px";
	$mQueryTab = "768px";
	$mQuerySm = "1024px";
	$mQueryMd = "1367px";
	$mQueryLg = "1600px";
	$mQueryXl = "1800px";

//* Misc. */

	$home = "pages()->get('/')";
	$pageFullUrl = $page->url;
	$pageTitle = $page->title;
	$pageNameHyph = $sanitizer->hyphenCase($page->name);

	$bookLink = $pages->get("/")->book_now_link;

	// Number of VR Headsets we currently have
	$hmdCount = 12;

	// $page->id == 1 refers to the home page
	$atHome = $page->id == 1 ? true : false;

//* Paths */

	$homePath = $config->urls->templates;
	$imagesPath = $homePath."images/";
	$textPath = $homePath."images/text/";
	$bgPath = $homePath."images/backgrounds/";
	$logosPath = $homePath."images/logos/";
	$homeHeroPath = $homePath."images/heroes/home/";
	$heroPath = $homePath."images/heroes/";
	$jsPath = $homePath."scripts/";
	$cssPath = $homePath."styles/";
	$favIconsPath = $homePath."images/favicons/";
	$headingPath = $homePath."images/headings/";

//* Social */

	$phoneNumber = $pages->get("/")->phone_number;
	$facebookUrl = $pages->get("/")->url_facebook;
	$twitterUrl = $pages->get("/")->url_twitter;
	$instagramUrl = $pages->get("/")->url_instagram;
	$linkedinUrl = $pages->get("/")->url_linkedin;
	$youtubeUrl = $pages->get("/")->url_youtube;
	$tiktokUrl = $pages->get("/")->url_tiktok;

//***** IMAGES *****/

	// Try to keep all $jpgQ images between 55-65% and $webpQ images between 60%-70%

    //* HEROES */

	$heroQuality = $atHome ? $page->home_hero->img_quality : $page->img_quality;

	// Hero image quality options
	switch ($heroQuality) {
		case '1': $webpQ = 50; $jpgQ = 55; break;
		case '2': $webpQ = 60; $jpgQ = 65; break;
		case '3': $webpQ = 70; $jpgQ = 75; break;
		case '4': $webpQ = 80; $jpgQ = 80; break;
		default: $webpQ = 60; $jpgQ = 65; break;
	}

	//* HEROES */

	$heroOptions = array( 'quality' => $jpgQ, 'webpAdd' => true, 'webpQuality' => $webpQ, 'sharpening' => 'none' );

	if ($atHome) {
		$heroBg = $page->home_hero->hero_bg->size(1920, 1280, $heroOptions);
	} else {
		$hero_sm = $page->hero_bg->size(1440, 675, $heroOptions);
		$hero_md = $page->hero_bg->size(1920, 900, $heroOptions);
	}

	//* LOGO */

	$logoOptions = array( 'quality' => 90, 'webpAdd' => true, 'webpQuality' => 90, 'sharpening' => 'none' );

	$logo_sm = $pages->get("/")->vrealms_logo->size(300, 300, $logoOptions);
	$logo_lg = $pages->get("/")->vrealms_logo->size(560, 560, $logoOptions);
