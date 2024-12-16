<?php

    $hero = $page->home_hero;
	$heading = $hero->title;
	$heroBgAlt = $hero->alt_tag;
	$heroHyph = $sanitizer->hyphenCase($heading);
	$heroTextAlt = $hero->hero_text_alt_tag;
	$heroTextPath = $homeHeroPath . $heroHyph . "/". $heroHyph;

	switch ($heading) {
		case 'Mobile Services': $class = "mobServHero"; break;
		case 'Grand Opening': $class = "goHero"; break;
		case 'What Realms' : $class = "wrHero"; break;
	}

?>

<div class="hero homeHero <?=$class?>">

	<picture>
		<source type="image/webp" srcset="<?=$heroBg->webp->url?>" />
		<source type="image/jpg" srcset="<?=$heroBg->url?>" />
		<img src="<?= $heroBg->url ?>" alt="<?=$heroBgAlt?>" />
	</picture>

	<div id="heroGradient"></div>

	<div class="heroText mob">
		<img src="<?=$heroTextPath?>-text-m.svg" alt='<?=$heroTextAlt?>'/>
	</div>

	<div class="heroText dt">
		<img src="<?=$heroTextPath?>-text.svg" alt='<?=$heroTextAlt?>' />
	</div>

</div>