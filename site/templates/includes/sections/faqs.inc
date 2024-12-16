<div id="faqs">
	<div class="vr-loader-wrap"><div class="vr-loader"></div></div>
	<div class="faqs-inner">
	<?php
		// Fetch all FAQ pages.
		$faqs = $pages->get("/faqs/")->children();
		$totalFaqs = count($faqs); // Total number of FAQs.
		$faqsPerPage = 3; // Number of FAQs per page.
		$totalPages = ceil($totalFaqs / $faqsPerPage); // Calculate total pages.

		// Get the current page from the query string or default to page 1.
		$currentPage = isset($_GET['page']) ? (int) $_GET['page'] : 1;
		if ($currentPage < 1) { $currentPage = 1; }
		if ($currentPage > $totalPages) { $currentPage = $totalPages; }

		// Calculate the offset for the current page.
		$offset = ($currentPage - 1) * $faqsPerPage;

		// Slice the FAQs array for the current page.
		$faqsToShow = $faqs->slice($offset, $faqsPerPage);

		// Display the FAQs for the current page.
		foreach ($faqsToShow as $faq): 
	?>

		<div class="faq">
			<h3><?= $faq->title?></h3>
			<div class="faqDetails"><?= $faq->details ?></div>
		</div>

	<?php endforeach; ?>
	</div>
	<div class="pagination">
		<?php
			// Generate pagination links.
			for ($i_page = 1; $i_page <= $totalPages; $i_page++) {
				$isActive = $i_page === $currentPage ? 'active' : '';
				echo '<a href="?page=' .  $i_page . '" data-page="'.$i_page.'" class="pagination-btn ' . $isActive . '"><button class="btn pageBtn">' . $i_page . '</button></a>';
			}
		?>
	</div>

</div>
