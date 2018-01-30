<div id="uitpas-search"
     <?php if ($card_systems_string): ?>
        data-card-systems-checked="<?php print $card_systems_string; ?>"
     <?php endif; ?>
     data-card-systems-visible="<?php print $filter_cardsystem; ?>"
     data-elastic-search-url="<?php print $url_uitpas; ?>"
     data-fuzzy-search="<?php print $fuzzy_search; ?>"
     data-last-chance-weeks="<?php print $last_chance; ?>"
     data-search-placeholder-text="<?php print $placeholder; ?>"
     data-uit-databank-url-prefix="<?php print $url_uitdatabank; ?>"
     data-in-spotlight-sticky="<?php print $spotlight; ?>"
     data-embedded="true"
     data-show-active-advantages="true"
     data-show-permanent-card-system-advantages="true"
     data-show-published-advantages="false"
     data-default-thumb-url="<?php print $thumb; ?>">
</div>
<script type="text/javascript" src="<?php print $jsscript; ?>"></script>