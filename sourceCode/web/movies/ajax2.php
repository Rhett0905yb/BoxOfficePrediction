<?php
$m = new MongoClient();
$db = $m->groupProject;
$collection = $db->Movie;
$getValue = $_GET['val'];
$actor_name = $_GET['actor'];

$c = $collection->count(array('$or' => array( 
                                 array('actor/actress1' => $actor_name), array('actor/actress2' => $actor_name),
                                 array('actor/actress3' => $actor_name), array('actor/actress4' => $actor_name)
              )));
if($getValue == "labels")
{
    $cursor = $collection->find(array('$or' => array( 
                                 array('actor/actress1' => $actor_name), array('actor/actress2' => $actor_name),
                                 array('actor/actress3' => $actor_name), array('actor/actress4' => $actor_name)
              )));
    $i = 0;
    foreach ($cursor as $document) {
        $i++;
      echo '"'.$document["Title"].'"';
      if($i!=$c)
        echo ', ';
    }
}
elseif($getValue == "boxOffice")
{
    $cursor = $collection->find(array('$or' => array( 
                                 array('actor/actress1' => $actor_name), array('actor/actress2' => $actor_name),
                                 array('actor/actress3' => $actor_name), array('actor/actress4' => $actor_name)
              )));
    $i = 0;
    foreach ($cursor as $document) {
        $i++;
      echo $document["box_office"];
      if($i!=$c)
        echo ', ';
    }
}
elseif($getValue == "budget")
{
    $cursor = $collection->find(array('$or' => array( 
                                 array('actor/actress1' => $actor_name), array('actor/actress2' => $actor_name),
                                 array('actor/actress3' => $actor_name), array('actor/actress4' => $actor_name)
              )));
    $i = 0;
    foreach ($cursor as $document) {
        $i++;
      echo $document["budget"];
      if($i!=$c)
        echo ', ';
    }
}

?>