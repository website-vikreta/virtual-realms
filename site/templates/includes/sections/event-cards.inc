

<div class="cardWrapper">
	<div class="swiper event-card-slider">
	<div class="cards swiper-wrapper">

		<?php

		$cards = $pages->get("/parties-events/")->children();

		$count = 0;

		foreach ($cards as $card):

			$count++;

			$cardTitle = $card->title;
			$cardTitleCc = $sanitizer->camelCase($cardTitle);
			$cardTitleHc = $sanitizer->hyphenCase($cardTitle);
			$cover = $card->card_cover;
			$altTag = $card->alt_tag;
			$details = $card->card_details;
			$btnLink = $card->link_ext;

			/* Game cover options */
			switch ($card->img_quality) {
				case '1': $webpQ = 50; $jpgQ = 60; break;
				case '2': $webpQ = 65; $jpgQ = 65; break;
				case '3': $webpQ = 75; $jpgQ = 70; break;
				case '4': $webpQ = 85; $jpgQ = 80; break;
				default: $webpQ = 65; $jpgQ = 65; break;
			}

			$options = array( 'quality' => $jpgQ, 'webpAdd' => true, 'webpQuality' => $webpQ, 'sharpening' => 'none' );

			$cardCover = $cover->size(460, 287, $options);

		?>

		<section class="swiper-slide card eventCard eventCard<?= $count ?>">

			<div class="cardCover">
				<picture class="cardThumb">
					<?php
						echo '<source type="image/webp" srcset="' . $cardCover->webp->url . '" />';
						echo '<img data-type="jpg" data-src="' . $cardCover->url . '" alt="' . $altTag . ' card cover."/>';
					?>
				</picture>
			</div>

			<section class="cardInfo">
				<div class="heading">
					<h3><?= $cardTitle; ?></h3>
					<img src="<?= $imagesPath ?>/parties-events/<?= $cardTitleHc; ?>-card-heading.png" alt='' />
				</div>
				<div class="details">
					<?= $details; ?>
				</div>
				<a href="<?= $btnLink; ?>">
					<button class="btn" type="button" >
						MORE INFO
					</button>
				</a>
			</section>

		</section>

		<?php
			endforeach;
		?>

	</div>
	</div>
</div>
