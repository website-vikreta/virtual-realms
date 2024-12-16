

<div class="catWrapper">

	<div class="catBtns">

		<?php

		$count = 0;

		$catTags = $pages->get("/tags/")->children;

		foreach ($catTags as $tag):

			$count++;

			$tagName = $tag->title;
			$tagNameHyph = $sanitizer->hyphenCase($tagName);
			$tagNameCc = $sanitizer->camelCase($tagName);
			$icon = $tag->page_icon;

			if ($icon != ''):;

		?>

			<a href='#<?= $tagNameHyph ?>'>
				<button class='btn catBtn <?= $tagNameCc ?>'>
					<span class='icon'>
						<i class='ph-duotone ph-<?= $icon ?>'></i>
					</span>
					<span class='title'><?= $tagName ?></span>
				</button>
			</a>

		<?php
			endif;
			endforeach;
		?>

	</div>

</div>