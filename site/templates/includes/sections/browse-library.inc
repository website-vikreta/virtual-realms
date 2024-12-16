<?php

$browseLibAlt = 'Cyberpunk-style graphic that reads "With over 100 amazing VR titles to choose from... What realms will you explore."';

?>

<div class="browseLib">

	<div class="browseLibHead dt">
		<img loading="lazy" src="<?= $textPath ?>/browse-library/browse-library-text.jpg" alt='<?= $browseLibAlt ?>' />
	</div>
	<div class="browseLibHead mob">
		<img loading="lazy" src="<?= $textPath ?>/browse-library/browse-library-text-m.jpg" alt='<?= $browseLibAlt ?>' />
	</div>
	<a href="<?= $section->link_internal->url ?>">
		<button class="btn" type="button" >
			<?= $section->btn_text ?>
		</button>
	</a>

</div>
