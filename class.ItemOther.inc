<?php

class ItemOther extends Item {
    /**
     * add vote category
     * @return string
     */
    function display() {
        return '<h3>Other Vote</h3>'.parent::display();
    }
}