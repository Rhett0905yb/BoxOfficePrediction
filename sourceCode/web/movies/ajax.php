<?php
$m = new MongoClient();
$db = $m->groupProject;
$collection = $db->Movie;
$getValue = $_GET['val'];
$director_name = $_GET['director'];

$c = $collection->count(array("Directors"=>$director_name));

if($getValue == "labels")
{
    $cursor = $collection->find(array("Directors"=>$director_name));
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
    $cursor = $collection->find(array("Directors"=>$director_name));
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

    $cursor = $collection->find(array("Directors"=>$director_name));
    $i = 0;
    foreach ($cursor as $document) {
        $i++;
      echo $document["budget"];
      if($i!=$c)
        echo ', ';
    }
}

elseif($getValue == "imdb")
{
    $cursor = $collection->find(array("Directors"=>$director_name));
    $i = 0;
    foreach ($cursor as $document) {
        $i++;
      echo $document["IMDb_Rating"];
      if($i!=$c)
        echo ', ';
    }
}


?>