<?php
/**
 * Grant vote item.
 */
class ItemGrant extends Item {
    /**
     * add vote category
     * @return string
     */
    function display() {
        return '<h3>Grant Vote</h3>'.parent::display();
    }
}