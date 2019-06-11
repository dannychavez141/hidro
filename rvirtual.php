<!DOCTYPE html>
<html lang="zxx">
<?php error_reporting(0);
 include_once'./cabezera.php'; 
require 'conexion.php';

  ?>


<body>

    <!-- //banner bottom grids -->
    <!--/stats -->
    <section class="statistics py-5" id="stats">
        <div class="container py-md-5">
            <div class="row">
                <div class="offset-md-6">
                </div>
                <div class="col-md-6 progress-w3ls mt-5">
                    <?php  
$query = "SELECT * FROM hidroponia.reporte order by idreporte desc limit 1;";
    $resultado = $mysqli->query($query);
while($row = $resultado->fetch_array())
    {
?><h1 class="progress-w3" align="center">VALORES REGISTRADOS POR SENSORES</h1>
                    <div class="progress-one">
                        <h4 class="progress-w3">HUMEDAD DEL AMBIENTE: <?php echo $row[1]."%"; ?> </h4>
                        <div class="progress">
                            <div class="progress-bar progress-bar-striped" role="progressbar" style="width: <?php echo $row[1]."%";?>" aria-valuenow="<?php echo $row[1];?>" aria-valuemin="0" aria-valuemax="100"></div>
                        </div>
                    </div>
                    <div class="progress-one my-lg-4">
                        <h4 class="progress-w3">TEMPERATURADEL AMBIENTE: <?php echo $row[2]."°C"; ?> </h4>
                        <div class="progress">
                            <div class="progress-bar progress-bar-striped bg-danger" role="progressbar" style="width: <?php echo $row[2]."%";?>" aria-valuenow="<?php echo $row[2];?>" aria-valuemin="0" aria-valuemax="100"></div>
                        </div>
                    </div>
                    <div class="progress-one">
                        <h4 class="progress-w3">HUMEDAD DE SUELO JARDIN 1: <?php echo $row[3]."%"; ?></h4>
                        <div class="progress">
                            <div class="progress-bar progress-bar-striped bg-info" role="progressbar" style="width: <?php echo $row[3]."%";?>" aria-valuenow="<?php echo $row[3];?>" aria-valuemin="0" aria-valuemax="100"></div>
                        </div>
                    </div>
                    <div class="progress-one my-lg-4">
                        <h4 class="progress-w3">HUMEDAD DE SUELO JARDIN 2: <?php echo $row[4]."%"; ?> </h4>
                        <div class="progress">
                            <div class="progress-bar progress-bar-striped bg-warning" role="progressbar" style="width: <?php echo $row[4]."%";?>" aria-valuenow="<?php echo $row[4];?>" aria-valuemin="0" aria-valuemax="100"></div>
                        </div>
                    </div>
                    <div class="progress-one">
                        <h4 class="progress-w3">HUMEDAD DE SUELO JARDIN 3: <?php echo $row[5]."%"; ?> </h4>
                        <div class="progress">
                            <div class="progress-bar progress-bar-striped bg-success" role="progressbar" style="width: <?php echo $row[5]."%";?>" aria-valuenow="<?php echo $row[5];?>" aria-valuemin="0" aria-valuemax="100"></div>
                        </div>
                    </div>

                    <?php } ?>
                </div>

            </div>
        </div>
    </section>
 
</body>

</html>