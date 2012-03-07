(function ($) {
    $(document).ready(function(){
        // transform "action" divs into list items
        $el = $('.views-field-field-action-nid');
        $el.wrapInner('<ol/>').find('div').wrap('<li class="numbered"/>');
    });
    })(jQuery);