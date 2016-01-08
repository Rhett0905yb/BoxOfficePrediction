<?php
error_reporting(E_ALL);
ini_set('display_errors', 'On');
?>

<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>Movies</title>
    <!-- Tell the browser to be responsive to screen width -->
    <meta content="width=device-width, initial-scale=1, maximum-scale=1, user-scalable=no" name="viewport">
    <!-- Bootstrap 3.3.5 -->
    <link rel="stylesheet" href="bootstrap/css/bootstrap.min.css">
    <!-- Font Awesome -->
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/font-awesome/4.4.0/css/font-awesome.min.css">
    <!-- Ionicons -->
    <link rel="stylesheet" href="https://code.ionicframework.com/ionicons/2.0.1/css/ionicons.min.css">
    <!-- Theme style -->
    <link rel="stylesheet" href="dist/css/AdminLTE.min.css">
    <!-- AdminLTE Skins. Choose a skin from the css/skins
         folder instead of downloading all of them to reduce the load. -->
    <link rel="stylesheet" href="dist/css/skins/_all-skins.min.css">
    <!-- iCheck -->
    <link rel="stylesheet" href="plugins/iCheck/flat/blue.css">
    <!-- Morris chart -->
    <link rel="stylesheet" href="plugins/morris/morris.css">
    <!-- jvectormap -->
    <link rel="stylesheet" href="plugins/jvectormap/jquery-jvectormap-1.2.2.css">
    <!-- Date Picker -->
    <link rel="stylesheet" href="plugins/datepicker/datepicker3.css">
    <!-- Daterange picker -->
    <link rel="stylesheet" href="plugins/daterangepicker/daterangepicker-bs3.css">
    <!-- bootstrap wysihtml5 - text editor -->
    <link rel="stylesheet" href="plugins/bootstrap-wysihtml5/bootstrap3-wysihtml5.min.css">
    <script src="jquery-2.1.4.min.js"></script>
    <style>
     .input-group{
      margin-top:80px;
      width:1200px;
     }
    </style>

    <!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->
    <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->
    <!--[if lt IE 9]>
        <script src="https://oss.maxcdn.com/html5shiv/3.7.3/html5shiv.min.js"></script>
        <script src="https://oss.maxcdn.com/respond/1.4.2/respond.min.js"></script>
    <![endif]-->
  </head>
  <body class="hold-transition skin-blue sidebar-mini">
    <div class="wrapper">

      <!-- Left side column. contains the logo and sidebar -->
   
      <!-- Content Wrapper. Contains page content -->
      <div class="content-wrapper" style="margin-left:0px !important">
        <!-- Content Header (Page header) -->
      
<!--Calculation-->
          <script>
              function cal(){

                var minGross;
                var geoGross;
                var harGross;
                var maxGross;
                
     // Calculate minGross  --------------------------
                
                var max = coefDirector;
                var budget = document.getElementById("budget").value;
                if(coefActor>max){
                  max = coefActor;
                }
                else if(coefActress>max){
                  max = coefActress;
                }
                minGross = (max * budget).toFixed(2);
                document.getElementById('minGross').innerHTML = minGross;

     // Calculate geoGross  --------------------------

                geoGross = (budget * Math.pow((coefDirector*coefActor*coefActress),(1/3))).toFixed(2);
                document.getElementById('geoGross').innerHTML = geoGross;
     
     // Calculate harGross  --------------------------
                
                harGross = (budget * (3*coefDirector*coefActor*coefActress)/((coefDirector*coefActor)+(coefDirector*coefActress)+(coefActress*coefActor))).toFixed(2);
                document.getElementById('harGross').innerHTML = harGross;
     
     // Calculate maxGross  --------------------------   
                
                maxGross = (budget * (coefDirector+coefActor+coefActress)).toFixed(2);
                document.getElementById('maxGross').innerHTML = maxGross;

                document.getElementById('coefDir').innerHTML = coefDirector;
                document.getElementById('coefAct').innerHTML = coefActor;
                document.getElementById('coefActrs').innerHTML = coefActress;
                document.getElementById('cbudget').innerHTML = budget;
               }
          </script>

<!-- Director -->
        <!-- Main content -->
        <section class="content">
          <img src="cover.jpg"/ width="100%" height=300px>
          
          <!--Textfield -->
          <div class="input-group">
           <span class="input-group-addon" id="sizing-addon2"> Director</span>
            <input type="text" class="form-control" id="disabledInput1" disabled placeholder="..director.." aria-describedby="sizing-addon2"></input>     
           <span class="input-group-addon" id="sizing-addon2">Actor</span>
            <input type="text" class="form-control" id="disabledInput2" disabled placeholder="..actor.." aria-describedby="sizing-addon2"></input>
           <span class="input-group-addon" id="sizing-addon2">Actress</span>
            <input type="text" class="form-control" id="disabledInput3" disabled placeholder="..actress.." aria-describedby="sizing-addon2"></input>
           <span class="input-group-addon" id="sizing-addon2">Budget</span>
            <input type="text" class="form-control" id="budget" placeholder="..budget.." aria-describedby="sizing-addon2"></input>
            <button onclick="cal()" class="btn btn-default" style="position:absolute"><span class="glyphicon glyphicon-ok"></span>Cast</button>
          </div>

          <br>
             
         <div>
          <h4>
           <p align="center">Director coefficient: <span class="label label-primary" id="coefDir"></span>
           &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp Actor coefficient: <span class="label label-primary" id="coefAct"></span>
           &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp Actress coefficient: <span class="label label-primary" id="coefActrs"></span>
           &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp Budget: <span class="label label-primary" id="cbudget"></span>
           </p>
          </h4>

          <h3>
           <p align="center">Min: <span class="label label-success" id="minGross"></span>
           &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp Geometric mean: <span class="label label-success" id="geoGross"></span>
           &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp Harmonic mean: <span class="label label-success" id="harGross"></span>
           &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp Max: <span class="label label-success" id="maxGross"></span>
           </p>
          </h3> 
        </div>
          
          <div class="box box-default" style="margin-top:40px">
            <div class="box-header with-border">
              <h3 class="box-title">Directors</h3>
              <div class="box-tools pull-right">
                <button class="btn btn-box-tool" data-widget="collapse"><i class="fa fa-minus"></i></button>
                <button class="btn btn-box-tool" data-widget="remove"><i class="fa fa-remove"></i></button>
              </div>
            </div><!-- /.box-header -->
            <div class="box-body">
              <div class="row">
                <div class="col-md-6">
                  <div class="form-group">
                    <label>Choose a director</label>
                    <select class="form-control" id="select1" style="width: 100%;">
                      <?php
                        $m = new MongoClient();
                       // select a database
                       $db = $m->groupProject;
                       $collection = $db->Director;
                      
                       $cursor = $collection->distinct('Director');
                       // iterate cursor to display title of documents
                       sort($cursor);
                       foreach ($cursor as $document) {
                          echo "<option>".$document . "</option>";
                       }
                    ?>
                    </select>
                  </div><!-- /.form-group -->
                </div><!-- /.col -->
                <div class="col-md-6">
                </div><!-- /.col -->
              </div><!-- /.row -->
            </div><!-- /.box-body -->         
          </div><!-- /.box -->
<div id ='chart'></div>
    <canvas id="myChart" width="400" height="400"></canvas>
<div id ='pie'></div>    
    <canvas id="myPie" width="400" height="400" style="position: absolute; right: 175px;top: 710px; !important"></canvas>

<!-- Actor -->
<!-- Main content -->
        <section class="content">
          <div class="box box-default" style="height:150px">
            <div class="box-header with-border">
              <h3 class="box-title">Actors/Actresses</h3>
              <div class="box-tools pull-right">
                <button class="btn btn-box-tool" data-widget="collapse"><i class="fa fa-minus"></i></button>
                <button class="btn btn-box-tool" data-widget="remove"><i class="fa fa-remove"></i></button>
              </div>
            </div><!-- /.box-header -->
            <div class="">
              <div >
                <div class="col-md-6">
                  <div class="form-group">
                    <label>Choose an actor</label>
                    <select class="form-control" id="select2" style="width: 100%;">
                      <?php
                        $m = new MongoClient();
                       // select a database
                       $db = $m->groupProject;
                       $collection = $db->Actor;
                      
                       $cursor = $collection->distinct('Actor');
                       sort($cursor);
                       //$cursor->sort(array('Actor' => -1));
                       // iterate cursor to display title of documents
                        
                       foreach ($cursor as $document) {
                          echo "<option>".$document . "</option>";
                       }
                    ?>
                    </select>
                    
                  </div><!-- /.form-group -->
                </div><!-- /.col -->
                <div class="col-md-6">
                </div><!-- /.col -->
              </div><!-- /.row -->
            </div><!-- /.box-body --> 

            <div class="">
              <div>
                <div class="col-md-6">
                  <div class="form-group">
                    <label>Choose an actress</label>
                    <select class="form-control" id="select3" style="width: 100%;">
                      <?php
                        $m = new MongoClient();
                       // select a database
                       $db = $m->groupProject;
                       $collection = $db->Actor;
                      
                       $cursor = $collection->distinct('Actor');
                      // $cursor->sort(array("Actor" => -1));
                       // iterate cursor to display title of documents
                        sort($cursor);
                       foreach ($cursor as $document) {
                          echo "<option>".$document . "</option>";
                       }
                    ?>
                    </select>
                    
                  </div><!-- /.form-group -->
                </div><!-- /.col -->
                <div class="col-md-6">
                </div><!-- /.col -->
              </div><!-- /.row -->
            </div><!-- /.box-body --> 

          </div><!-- /.box -->

<div id ='line1'></div>
    <canvas id="myLine" width="400" height="400"></canvas>

<div id ='line2'></div>  
    <canvas id="myLine2" width="400" height="400" style="position:absolute; right: 230px;top: 1310px; !important"></canvas>

    <div class="control-sidebar-bg"></div>
    </div><!-- ./wrapper -->

    <!-- jQuery 2.1.4 -->
    <script src="plugins/jQuery/jQuery-2.1.4.min.js"></script>
    <!-- jQuery UI 1.11.4 -->
    <script src="https://code.jquery.com/ui/1.11.4/jquery-ui.min.js"></script>
    <!-- Resolve conflict in jQuery UI tooltip with Bootstrap tooltip -->
    <script>
      $.widget.bridge('uibutton', $.ui.button);
    </script>
    <!-- Bootstrap 3.3.5 -->
    <script src="bootstrap/js/bootstrap.min.js"></script>
    <!-- Morris.js charts -->
    <!-- Sparkline -->
    <script src="plugins/sparkline/jquery.sparkline.min.js"></script>
    <!-- jvectormap -->
    <script src="plugins/jvectormap/jquery-jvectormap-1.2.2.min.js"></script>
    <script src="plugins/jvectormap/jquery-jvectormap-world-mill-en.js"></script>
    <!-- jQuery Knob Chart -->
    <script src="plugins/knob/jquery.knob.js"></script>
    <!-- daterangepicker -->
    <script src="https://cdnjs.cloudflare.com/ajax/libs/moment.js/2.10.2/moment.min.js"></script>
    <script src="plugins/daterangepicker/daterangepicker.js"></script>
    <!-- datepicker -->
    <script src="plugins/datepicker/bootstrap-datepicker.js"></script>
    <!-- Bootstrap WYSIHTML5 -->
    <script src="plugins/bootstrap-wysihtml5/bootstrap3-wysihtml5.all.min.js"></script>
    <!-- Slimscroll -->
    <script src="plugins/slimScroll/jquery.slimscroll.min.js"></script>
    <!-- FastClick -->
    <script src="plugins/fastclick/fastclick.min.js"></script>
    <!-- AdminLTE App -->
    <script src="dist/js/app.min.js"></script>
    <!-- AdminLTE dashboard demo (This is only for demo purposes) -->
    <!-- AdminLTE for demo purposes -->
    <script src="dist/js/demo.js"></script>
    <script src="Chart.js"></script>
  </body>
</html>

<!--Bar graph-->
<script>
var coefDirector;
var coefActor;
var coefActress;

$(document).ready(function(){
    var ctx = document.getElementById("myChart").getContext("2d");

    var options = {
    //Boolean - Whether the scale should start at zero, or an order of magnitude down from the lowest value
    scaleBeginAtZero : true,

    //Boolean - Whether grid lines are shown across the chart
    scaleShowGridLines : true,

    //String - Colour of the grid lines
    scaleGridLineColor : "rgba(0,0,0,.05)",

    //Number - Width of the grid lines
    scaleGridLineWidth : 1,

    //Boolean - Whether to show horizontal lines (except X axis)
    scaleShowHorizontalLines: true,

    //Boolean - Whether to show vertical lines (except Y axis)
    scaleShowVerticalLines: true,

    //Boolean - If there is a stroke on each bar
    barShowStroke : true,

    //Number - Pixel width of the bar stroke
    barStrokeWidth : 2,

    //Number - Spacing between each of the X value sets
    barValueSpacing : 5,

    //Number - Spacing between data sets within X values
    barDatasetSpacing : 1,

    //String - A legend template

};
$("#select1").change(function(){
   $("#myChart").remove();
   $("#chart").append('<canvas id="myChart" width="400" height="400"></canvas>')
   
   var ctx = document.getElementById("myChart").getContext("2d");

var director = $(this).val();
$('#disabledInput1').val(director);

var response_labels = "";
var response_boxoffice = "";
var response_budget = "";
$.ajax({
    type: "get",
        async: false,
        cache: false,
    url:"./ajax.php",
    data:{
        "val":"labels",
        "director":director
    }
}).done(function(res){
    response_labels = JSON.parse("[" + res + "]");
});
$.ajax({
    type: "get",
        async: false,
        cache: false,
    url:"./ajax.php",
    data:{
        "val":"boxOffice",
        "director":director
    }
}).done(function(res){
    response_boxoffice = JSON.parse("[" + res + "]");
});
$.ajax({
    type: "get",
        async: false,
        cache: false,
    url:"./ajax.php",
    data:{
        "val":"budget",
        "director":director
    }
}).done(function(res){
    response_budget = JSON.parse("[" + res + "]");
});

// Calculate director coefficient 
var count = response_budget.length;
var i=0;
var total=0;

    for(i;i<count;i++){
      total+=response_boxoffice[i] / response_budget[i]; 
    }

    coefDirector = total / count;
   
console.log(coefDirector);

    var data = {
    labels: response_labels,
    datasets: [
        {
            label: "My First dataset",
            fillColor: "rgba(220,220,220,0.5)",
            strokeColor: "rgba(220,220,220,0.8)",
            highlightFill: "rgba(220,220,220,0.75)",
            highlightStroke: "rgba(220,220,220,1)",
            data: response_budget,
        },
        {
            label: "My Second dataset",
            fillColor: "rgba(151,187,205,0.5)",
            strokeColor: "rgba(151,187,205,0.8)",
            highlightFill: "rgba(151,187,205,0.75)",
            highlightStroke: "rgba(151,187,205,1)",
            data: response_boxoffice,
        }
    ]
};
ctx.canvas.width = 400;
ctx.canvas.height = 400;
var myBarChart = new Chart(ctx).Bar(data, options);
});
});
</script>



<!--Pie graph-->
<script>
$(document).ready(function(){
    
    var ctx = document.getElementById("myPie").getContext("2d");
  
    var options = {
    //Boolean - Whether we should show a stroke on each segment
    segmentShowStroke : true,

    //String - The colour of each segment stroke
    segmentStrokeColor : "#fff",

    //Number - The width of each segment stroke
    segmentStrokeWidth : 2,

    //Number - The percentage of the chart that we cut out of the middle
    percentageInnerCutout : 50, // This is 0 for Pie charts

    //Number - Amount of animation steps
    animationSteps : 100,

    //String - Animation easing effect
    animationEasing : "easeOutBounce",

    //Boolean - Whether we animate the rotation of the Doughnut
    animateRotate : true,

    //Boolean - Whether we animate scaling the Doughnut from the centre
    animateScale : false,

    //String - A legend template
    legendTemplate : "<ul class=\"<%=name.toLowerCase()%>-legend\"><% for (var i=0; i<segments.length; i++){%><li><span style=\"background-color:<%=segments[i].fillColor%>\"></span><%if(segments[i].label){%><%=segments[i].label%><%}%></li><%}%></ul>"
};

$("#select1").change(function(){
  $("#myPie").remove();
  $("#pie").append('<canvas id="myPie" width="400" height="400" style="position: absolute; right: 175px;top: 710px;"></canvas>')

  var ctx = document.getElementById("myPie").getContext("2d");
   
var director = $(this).val();
var response_labels = "";
var response_imdb = "";

$.ajax({
    type: "get",
        async: false,
        cache: false,
    url:"./ajax.php",
    data:{
        "val":"labels",
        "director":director
    }
}).done(function(res){
    response_labels = JSON.parse("[" + res + "]");
});

$.ajax({
    type: "get",
        async: false,
        cache: false,
    url:"./ajax.php",
    data:{
        "val":"imdb",
        "director":director
    }
}).done(function(res){
    response_imdb = JSON.parse("[" + res + "]");
});
    

    var max = response_imdb.length;
    var str = "";
    var say = 1;
    var count = 0;
    var colorValue = 0;

     for(count;count<max;count++)
    {  
       colorValue = 123456 + (count*8000);
  
       str += "{\"value\": "+ response_imdb[count] +", " + "\"color\": \"#"+colorValue +"\" , " +"\"label\": \""+ response_labels[count] +"\"}";
       
       if(say!=max){
         str += ", ";
         say++;
       }
    }
    var data = "["+str+"]";
    console.log(data);
    data = JSON.parse(data);
console.log(data);
ctx.canvas.width = 400;
ctx.canvas.height = 400;
var piechart = new Chart(ctx).Pie(data,options);
});
});
</script>



<!--Line graph-->
<script>
$(document).ready(function(){
    var ctx = document.getElementById("myLine").getContext("2d");
    var options = {

    ///Boolean - Whether grid lines are shown across the chart
    scaleShowGridLines : true,

    //String - Colour of the grid lines
    scaleGridLineColor : "rgba(0,0,0,.05)",

    //Number - Width of the grid lines
    scaleGridLineWidth : 1,

    //Boolean - Whether to show horizontal lines (except X axis)
    scaleShowHorizontalLines: true,

    //Boolean - Whether to show vertical lines (except Y axis)
    scaleShowVerticalLines: true,

    //Boolean - Whether the line is curved between points
    bezierCurve : true,

    //Number - Tension of the bezier curve between points
    bezierCurveTension : 0.4,

    //Boolean - Whether to show a dot for each point
    pointDot : true,

    //Number - Radius of each point dot in pixels
    pointDotRadius : 4,

    //Number - Pixel width of point dot stroke
    pointDotStrokeWidth : 1,

    //Number - amount extra to add to the radius to cater for hit detection outside the drawn point
    pointHitDetectionRadius : 20,

    //Boolean - Whether to show a stroke for datasets
    datasetStroke : true,

    //Number - Pixel width of dataset stroke
    datasetStrokeWidth : 2,

    //Boolean - Whether to fill the dataset with a colour
    datasetFill : true,

    //String - A legend template
    legendTemplate : "<ul class=\"<%=name.toLowerCase()%>-legend\"><% for (var i=0; i<datasets.length; i++){%><li><span style=\"background-color:<%=datasets[i].strokeColor%>\"></span><%if(datasets[i].label){%><%=datasets[i].label%><%}%></li><%}%></ul>"

};

$("#select2").change(function(){
  $("#myLine").remove();
  $("#line1").append('<canvas id="myLine" width="400" height="400"></canvas>')
   
var ctx = document.getElementById("myLine").getContext("2d");
var actor = $(this).val();

$('#disabledInput2').val(actor);

var response_labels = "";
var response_boxoffice = "";
var response_budget = "";

$.ajax({
    type: "get",
        async: false,
        cache: false,
    url:"./ajax2.php",
    data:{
        "val":"labels",
        "actor":actor
    }
}).done(function(res){
    console.log(res);
    response_labels = JSON.parse("[" + res + "]");
});

$.ajax({
    type: "get",
        async: false,
        cache: false,
    url:"./ajax2.php",
    data:{
        "val":"boxOffice",
        "actor":actor
    }
}).done(function(res){
    console.log(res);
    response_boxoffice = JSON.parse("[" + res + "]");
});

$.ajax({
    type: "get",
        async: false,
        cache: false,
    url:"./ajax2.php",
    data:{
        "val":"budget",
        "actor":actor
    }
}).done(function(res){
    console.log(res);
    response_budget = JSON.parse("[" + res + "]");
});

// Calculate actor coefficient 
var count = response_budget.length;
var i=0;
var total=0;

    for(i;i<count;i++){
      total+=response_boxoffice[i] / response_budget[i]; 
    }

    coefActor = total / count;

console.log(coefActor);

    var data2 = {
    labels: response_labels,
    datasets: [
        {
            label: "boxOffice",
            fillColor: "rgba(220,220,220,0.2)",
            strokeColor: "rgba(220,220,220,1)",
            pointColor: "rgba(220,220,220,1)",
            pointStrokeColor: "#fff",
            pointHighlightFill: "#fff",
            pointHighlightStroke: "rgba(220,220,220,1)",
            data: response_budget
        },
        {
            label: "budget",
            fillColor: "rgba(151,187,205,0.2)",
            strokeColor: "rgba(151,187,205,1)",
            pointColor: "rgba(151,187,205,1)",
            pointStrokeColor: "#fff",
            pointHighlightFill: "#fff",
            pointHighlightStroke: "rgba(151,187,205,1)",
            data: response_boxoffice
        }
    ]
};

ctx.canvas.width = 400;
ctx.canvas.height = 400;
var myLineChart = new Chart(ctx).Line(data2, options);

});
});
</script>   


<script>
$(document).ready(function(){
    var ctx = document.getElementById("myLine2").getContext("2d");
    var options = {

    ///Boolean - Whether grid lines are shown across the chart
    scaleShowGridLines : true,

    //String - Colour of the grid lines
    scaleGridLineColor : "rgba(0,0,0,.05)",

    //Number - Width of the grid lines
    scaleGridLineWidth : 1,

    //Boolean - Whether to show horizontal lines (except X axis)
    scaleShowHorizontalLines: true,

    //Boolean - Whether to show vertical lines (except Y axis)
    scaleShowVerticalLines: true,

    //Boolean - Whether the line is curved between points
    bezierCurve : true,

    //Number - Tension of the bezier curve between points
    bezierCurveTension : 0.4,

    //Boolean - Whether to show a dot for each point
    pointDot : true,

    //Number - Radius of each point dot in pixels
    pointDotRadius : 4,

    //Number - Pixel width of point dot stroke
    pointDotStrokeWidth : 1,

    //Number - amount extra to add to the radius to cater for hit detection outside the drawn point
    pointHitDetectionRadius : 20,

    //Boolean - Whether to show a stroke for datasets
    datasetStroke : true,

    //Number - Pixel width of dataset stroke
    datasetStrokeWidth : 2,

    //Boolean - Whether to fill the dataset with a colour
    datasetFill : true,

    //String - A legend template
    legendTemplate : "<ul class=\"<%=name.toLowerCase()%>-legend\"><% for (var i=0; i<datasets.length; i++){%><li><span style=\"background-color:<%=datasets[i].strokeColor%>\"></span><%if(datasets[i].label){%><%=datasets[i].label%><%}%></li><%}%></ul>"

};

$("#select3").change(function(){
  $("#myLine2").remove();
  $("#line2").append('<canvas id="myLine2" width="400" height="400" style="position:absolute; right: 230px;top: 1310px; !important"></canvas>')
   
  var ctx = document.getElementById("myLine2").getContext("2d");
var actor = $(this).val();

$('#disabledInput3').val(actor);

var response_labels = "";
var response_boxoffice = "";
var response_budget = "";

$.ajax({
    type: "get",
        async: false,
        cache: false,
    url:"./ajax2.php",
    data:{
        "val":"labels",
        "actor":actor
    }
}).done(function(res){
    console.log(res);
    response_labels = JSON.parse("[" + res + "]");
});

$.ajax({
    type: "get",
        async: false,
        cache: false,
    url:"./ajax2.php",
    data:{
        "val":"boxOffice",
        "actor":actor
    }
}).done(function(res){
    console.log(res);
    response_boxoffice = JSON.parse("[" + res + "]");
});

$.ajax({
    type: "get",
        async: false,
        cache: false,
    url:"./ajax2.php",
    data:{
        "val":"budget",
        "actor":actor
    }
}).done(function(res){
    console.log(res);
    response_budget = JSON.parse("[" + res + "]");
});

// Calculate actor coefficient 
var count = response_budget.length;
var i=0;
var total=0;

    for(i;i<count;i++){
      total+=response_boxoffice[i] / response_budget[i]; 
    }

    coefActress = total / count;
    
console.log(coefActress);

    var data2 = {
    labels: response_labels,
    datasets: [
        {
            label: "boxOffice",
            fillColor: "rgba(220,220,220,0.2)",
            strokeColor: "rgba(220,220,220,1)",
            pointColor: "rgba(220,220,220,1)",
            pointStrokeColor: "#fff",
            pointHighlightFill: "#fff",
            pointHighlightStroke: "rgba(220,220,220,1)",
            data: response_budget
        },
        {
            label: "budget",
            fillColor: "rgba(151,187,205,0.2)",
            strokeColor: "rgba(151,187,205,1)",
            pointColor: "rgba(151,187,205,1)",
            pointStrokeColor: "#fff",
            pointHighlightFill: "#fff",
            pointHighlightStroke: "rgba(151,187,205,1)",
            data: response_boxoffice
        }
    ]
};

ctx.canvas.width = 400;
ctx.canvas.height = 400;
var myLineChart = new Chart(ctx).Line(data2, options);

});
});
</script>  