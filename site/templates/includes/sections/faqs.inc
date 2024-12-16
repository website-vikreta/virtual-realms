
<div id="faqs">

	<?php

		$faqs = $pages->get("/faqs/")->children();
		$faqPages = 3; // Number of FAQ pages to display.

		$count = 0;

		foreach ($faqs as $faq):

			$count++;

			if ($count == 10 && $atHome == true) { break; }

	?>

		<div class = "faq">
			<h3><?= $faq->title ?></h3>
			<div class="faqDetails"><?= $faq->details ?></div>
		</div>

	<?php endforeach;

		echo '<div class="pagination">';

			$count = 1;
			while ($count <= $faqPages) {
				echo '<button href="" class="btn pageBtn">'. $count++ .'</button>';
			};

		echo '</div>';

	?>

</div>