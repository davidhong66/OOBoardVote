<!DOCTYPE html>
<html lang="en">
<head>
  <title>GRANT CYCLE 02-13-2015 Report</title>
  <meta charset="utf-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1" />
  <link rel="stylesheet" href="http://maxcdn.bootstrapcdn.com/bootstrap/3.2.0/css/bootstrap.min.css" />
  <link href='http://fonts.googleapis.com/css?family=Droid+Serif:400,400italic,700,700italic' rel='stylesheet' type='text/css'>

  <link rel="stylesheet" href="style.css">
 <style>
     *{
         font-family: 'Droid Serif', serif;
     }
</style>
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.11.1/jquery.min.js"></script>
  <script src="http://maxcdn.bootstrapcdn.com/bootstrap/3.2.0/js/bootstrap.min.js"></script>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
</head>
<body>
<?php
function __autoload($class_name) {
    include('class.'. $class_name. '.inc');
}
?>
<div class="container-fluid" style="background-color: #140000;">
<div class="container" style="background-color: white; margin-top:10px;padding-top:10px; margin-bottom:10px;padding-bottom:10px;">
<h2>GRANT CYCLE 02-13-2015</h2>
<?php
$db = new db(EZSQL_DB_USER, EZSQL_DB_PASSWORD, EZSQL_DB_NAME, EZSQL_DB_HOST);
$vote_ids = $db->get_results("select pi_id from hong_poll_items where group_id=3650");
if(!empty($vote_ids)){
    foreach($vote_ids as $vote_id) {
        $item_db = Item::load($vote_id->pi_id);
	echo $item_db->display();
    }
}
?>
<footer class="footer">
  <div class="container">
          <p class="text-muted">International Community Foundation |
            2505 N Avenue, National City, CA 91950 USA <br />
        </p>
      </div>
</footer>
</div>
</div>
</body>
</html>