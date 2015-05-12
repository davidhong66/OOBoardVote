<?php
/**
 * Item
 */
abstract class Item{
    const ITEM_TYPE_FUND = 'Fund';
    const ITEM_TYPE_EXPENSE = 'Charitable Expense';
    const ITEM_TYPE_GRANT = 'Grant';
    const ITEM_TYPE_OTHER = 'Other';

    static public $valid_item_types = array(
        Item::ITEM_TYPE_FUND=> 'Fund',
        Item::ITEM_TYPE_EXPENSE => 'Expense',
        Item::ITEM_TYPE_GRANT => 'Grant',
        Item::ITEM_TYPE_OTHER => 'Other',
        );
    //
    public $item_content;

    /**
     * Contructor
     * @param array $data
     */
    function __construct($data) {
        $this->item_content = $data;
    }
    /**
     * Matic __toString
     * @return string in html
     */
    function __toString() {
        return $this->display();
    }
    /**
     * Load an Item
     * @param int $item_id
     * @throws Exception
     */
    final public static function load($item_id){

        $db = new db(EZSQL_DB_USER, EZSQL_DB_PASSWORD, EZSQL_DB_NAME, EZSQL_DB_HOST);
        $my_query  = 'select hong_poll_items.* ';
        $my_query .= 'from hong_poll_items ';
        $my_query .= 'where pi_id = "'.(int)$item_id .'" ';
        $my_query .='limit 1';

        $row = $db->get_row($my_query, ARRAY_A);

        if(!empty($row)){
            return self::getInstance($row['pi_nature'], $row);
        }
        else{
            throw new Exception('Item not found');
        }
    }
    /**
     * With an item id, return an instance of tha subclass
     * @param string $item_type
     * @param array $data
     * @return Item subclass
     */
    final public static function getInstance($item_type, $data){
        $class_name = 'Item'. self::$valid_item_types[$item_type];
        if(!class_exists($class_name)){
            throw new Exception('Item subclass not found. Please implement'.__CLASS__);
        }
        return new $class_name($data);
    }
    /**
     * Get rid of special letters for display in html
     * @param sting $text
     * @return string
     */
    static function clean_text($text){
	$text_return = str_replace(
	array('{',  '$', '\'', '"', '\\'),
	array('&#123;', '&#036;', '&#039;', '&quot;', '&#92;'), $text);
	return($text_return);
    }
    /**
     * Display an vote item in html
     * @return string
     */
    function display() {
        $table_html="<center><table class='table' width='95%'>";

        foreach($this->item_content as $key=>$val) {
            if(!empty($val)){
                if(strpos($key,'date')!==false && $val >10)
                    $val = date('F j, Y', $val);
                if($val=='1') $val = 'Yes';
                    $outkey = ucwords(str_replace(array('_', 'pi'), array(' ',''),$key));
                    $table_html.= "<tr><td width='25%' align='right'><strong>$outkey</strong></td>"
                            . "<td align='left'>".self::clean_text($val)."</td></tr>";
            }
        }
        $table_html.="</table></center><hr />";
        return $table_html;
    }
}
?>