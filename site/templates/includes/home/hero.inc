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
	<div class="heroText">
		<div class="heroText-inner mob">
			<img src="<?=$heroTextPath?>-text-m.svg" alt='<?=$heroTextAlt?>'/>
		</div>
		<div class="heroText-inner dt">
			<img src="<?=$heroTextPath?>-text.svg" alt='<?=$heroTextAlt?>' />
		</div>
		<?php if ( $page->home_hero_cta_text != NULL ): ?>
			<div class="heroButton">
				<a href="<?=$page->home_hero_cta_link?>"><button class="btn" type="button"><?=$page->home_hero_cta_text?></button></a>
			</div>
		<?php endif; ?>
	</div>
	<div class="hero-down-scroll">
		<button class="btn" type="button"><i class="ph-duotone ph-arrow-fat-line-down"></i></button>
	</div>
</div>