<?php
/**
 * Fund vote item.
 */
class ItemFund extends Item {
    /**
     * add vote category
     * @return string
     */
    function display() {
        return '<h3>New Fund Vote</h3>'.parent::display();
    }    
}