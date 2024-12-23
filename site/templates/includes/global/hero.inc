
<?php

	$hero_sm = $page->hero_bg->size(1440, 675, $heroOptions);
	$hero_md = $page->hero_bg->size(1920, 900, $heroOptions);

	switch ($pageTitle) {
		case "VR Library": $hideHero = true; break;
		default: $cover = $hideHero = false; break;
	}

	if ($hideHero == false):

?>

<div class="hero">

	<picture>
		<source type="image/webp"
			media="(max-width: <?= $mQueryTab ?>)"
			data-srcset="<?= $hero_md->webp->url ?>"
		/>
		<source type="image/webp"
			media="(max-width: <?= $mQueryMd ?>)"
			data-srcset="<?= $hero_sm->webp->url ?>"
		/>
		<source type="image/webp"
			media="(max-width: 10000px)"
			data-srcset="<?= $hero_md->webp->url ?>"
		/>
		<source type="image/jpg"
			media="(max-width: <?= $mQueryTab ?>)"
			data-srcset="<?= $hero_md->url ?>"
		/>
		<source type="image/jpg"
			media="(max-width: <?= $mQueryMd ?>)"
			data-srcset="<?= $hero_sm->url ?>"
		/>
		<source type="image/jpg"
			media="(max-width: 10000px)"
			data-srcset="<?= $hero_md->url ?>"
		/>
		<img
			data-src="<?= $hero_md->url ?>"
			alt="<?= $page->alt_tag ?>"
		/>
	</picture>

	<div id="heroGradient"></div>

	<h1> <?= $pageTitle ?> </h1>

	<div class="heroText mob">
		<img data-src="<?= $heroPath ?><?= $pageNameHyph ?>/<?= $pageNameHyph ?>-hero-heading-m.svg" alt='<?= $pageTitle ?> heading text graphic (mobile).' />
	</div>

	<div class="heroText dt">
		<img data-src="<?= $heroPath ?><?= $pageNameHyph ?>/<?= $pageNameHyph ?>-hero-heading.svg" alt='<?= $pageTitle ?> heading text graphic (desktop).' />
	</div>

</div>

<?php endif; ?>