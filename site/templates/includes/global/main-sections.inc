<?php

	foreach ($page->main_sections as $section) :

		$heading = $section->title;
		$lead = $section->lead;

		$classTag = $heading == "FAQs" ? "faqs" : $sanitizer->camelCase($heading);
		$headingHyph = $sanitizer->hyphenCase($heading);

		$hideHeadLead = $section->hide_head_lead == true ? true : false;
		$headExt = $heading == "Ubisoft"? "svg" : "png";

		$template = $section->template->name;

		// MORE LINK
		if ($section->more_text) {
			$moreUrl = $section->link_internal->url;

			if ($section->more_text != "") {
				$moreLink =
				'<div class="moreLink">
					<a href="' . $moreUrl . '">' . $section->more_text . '
						<i class="ph-duotone ph-arrow-fat-right"></i>
					</a>
				</div>';
			} else { $moreLink = '';}
		}

		if ($section->bg != NULL) {
			// Background Image /
			switch ($section->img_quality) {
				case '1': $webpQ = 50; $jpgQ = 50; break;
				case '2': $webpQ = 60; $jpgQ = 60; break;
				case '3': $webpQ = 70; $jpgQ = 70; break;
				case '4': $webpQ = 80; $jpgQ = 80; break;
				default: $webpQ = 60; $jpgQ = 60; break;
			}

			$bgOptions = array( 'quality' => $jpgQ, 'webpAdd' => true, 'webpQuality' => $webpQ, 'sharpening' => 'none' );

			$section_bg_xl = $section->bg->size(3840, 1540, $bgOptions);
			$section_bg = $section->bg->size(1920, 770, $bgOptions);

			$altTag = $section->alt_tag != "" ? $section->alt_tag . " background." : "";
		}

		$cardSec = ($template == "sec-game-cards" || "sec-event-cards") ? " cardSec" : "";

?>

	<section id="home-<?= $classTag ?>" class="<?= $classTag ?>Section mainSection<?= $cardSec ?>">

		<div class="bgImg">
			<?php if ($section->bg != NULL): ?>
				<picture>
					<source type="image/webp"
						media="(max-width: <?= $mQueryXl ?>)"
						srcset="<?= $section_bg->webp->url ?>"
					/>
					<source type="image/webp"
						media="(max-width: 10000px)"
						srcset="<?= $section_bg_xl->webp->url ?>"
					/>
					<source type="image/jpg"
						media="(max-width: <?= $mQueryXl ?>)"
						srcset="<?= $section_bg->url ?>"
					/>
					<source type="image/jpg"
						media="(max-width: 10000px)"
						srcset="<?= $section_bg_xl->url ?>"
					/>
					<img loading="lazy" src="<?= $section_bg->url ?>" alt="<?= $altTag ?>" />
				</picture>
			<?php endif; ?>
			<div class="secGradient secGradientTop"></div>
			<div class="secGradient secGradientBot"></div>
		</div>

		<div class="mainContent">

			<h2><?= $heading ?></h2>

			<?php if ($hideHeadLead == false): ?>
				<div class="headLead">
					<div class="head dt">
						<img loading="lazy" src="<?= $headingPath ?><?= $headingHyph ?>-heading.<?= $headExt ?>" alt="<?= $heading ?> heading text graphic (desktop)." />
					</div>
					<div class="head mob">
						<img loading="lazy" src="<?= $headingPath ?><?= $headingHyph ?>-heading-m.<?= $headExt ?>" alt="<?= $heading ?> heading text graphic (mobile)." />
					</div>
					<div class="lead"><?= $lead ?></div>
				</div>
			<?php endif;

				switch ($section->template->name) {
					case 'sec-cat-btns': include("./includes/sections/cat-btns.inc"); break;
					case 'sec-game-cards': include("./includes/sections/game-cards.inc"); break;
					case 'sec-all-game-cards': include("./includes/sections/all-game-cards.inc"); break;
					case 'sec-event-cards': include("./includes/sections/event-cards.inc"); break;
					case 'sec-browse-library': include("./includes/sections/browse-library.inc"); break;
					case 'sec-faqs': include("./includes/sections/faqs.inc"); break;
					case 'sec-events': include("./includes/sections/events.inc"); break;
					case 'sec-subscribe': include("./includes/sections/subscribe.inc"); break;
					default: ''; }
				if ($section->more_text) { echo $moreLink ;}
			?>

		</div>

		<?php switch ($section->template->name) {
				case 'sec-game-cards': include("./includes/sections/game-card-modals.inc"); break;
				case 'sec-all-game-cards': include("./includes/sections/game-card-modals.inc"); break;
				default: '';
				break; }
		?>

	</section>

<?php endforeach; ?>