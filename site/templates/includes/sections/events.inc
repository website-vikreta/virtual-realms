

<div class="events">



	<?php

	$sections = $pages->get("/parties-events/")->children();

	$count = 0;

	foreach ($sections as $section):

		$count++;

		$eventTitle = $section->title;
		$eventTitleCc = $sanitizer->camelCase($eventTitle);
		$eventTitleHc = $sanitizer->hyphenCase($eventTitle);
		$cover = $section->card_cover;
		$altTag = $section->alt_tag;
		$details = $section->details;
		$contactLink = $pages->get("/contact/")->url;

		/* Game cover options */
		switch ($section->img_quality) {
			case '1': $webpQ = 50; $jpgQ = 60; break;
			case '2': $webpQ = 65; $jpgQ = 65; break;
			case '3': $webpQ = 75; $jpgQ = 70; break;
			case '4': $webpQ = 85; $jpgQ = 80; break;
			default: $webpQ = 65; $jpgQ = 65; break;
		}

		$options = array( 'quality' => $jpgQ, 'webpAdd' => true, 'webpQuality' => $webpQ, 'sharpening' => 'none' );

		$eventCover = $cover->size(830, 510, $options);

	?>

	<section id="<?= $eventTitleHc; ?>" class="event event<?= $count ?>">

		<div class="eventCover">
			<picture class="eventImg">
				<?php
					echo '<source type="image/webp" srcset="' . $eventCover->webp->url . '" />';
					echo '<img loading="lazy" data-type="jpg" data-src="' . $eventCover->url . '" alt="' . $altTag . '"/>';
				?>
			</picture>
		</div>

		<section class="eventInfo">
			<div class="heading">
				<h3><?= $eventTitle; ?></h3>
				<div class="head dt">
					<img loading="lazy" src="<?= $imagesPath ?>/parties-events/<?= $eventTitleHc; ?>-sec-heading-lft.png" alt="' . $altTag . ' cover." />
				</div>
				<div class="head mob">
					<img loading="lazy" src="<?= $imagesPath ?>/parties-events/<?= $eventTitleHc; ?>-sec-heading.png" alt="' . $altTag . ' cover." />
				</div>
			</div>
			<div class="details"><?= $details; ?></div>
			<div class="btns">
				<a href="<?= $bookLink; ?>">
					<button class="btn bookBtn" type="button" >
						Book Now
					</button>
				</a>
				<a href="<?= $contactLink; ?>">
					<button class="btn contactBtn" type="button" >
						Contact Us
					</button>
				</a>
			</div>
		</section>

	</section>

	<?php
		endforeach;
	?>

</div>