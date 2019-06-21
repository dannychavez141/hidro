
<!DOCTYPE html>
<html lang="zxx">
<?php error_reporting(0);
 include_once'./cabezera.php';  
require 'conexion.php';
 	$conf=$_GET['tconf'];
 	$bus = $_POST['tbus'];
 	if ($conf) {
 echo "<script>alert('Operacion Realizada exitosamente');</script>";

}


 ?>
<body>
		<!-- banner -->
		<div class="banner_w3lspvt-2">
			<ol class="breadcrumb">
				<li class="breadcrumb-item"><a href="index.php" class="font-weight-bold">Inicio</a></li>
				<li class="breadcrumb-item" aria-current="page">Reporte de Gatos</li>
			</ol>
		</div>
		<!-- //banner -->
<!-- //main banner -->
	<!-- contact -->

	<center><h3 >Alumnos Registrados</h3>
	<hr>
<div class="d-flex mt-lg-1 mt-sm-2 mt-3 justify-content-center">
						<!-- search -->
						<div class="search-w3layouts mr-3">
							<form action="alumno.php" method="post" class="search-bottom-wthree d-flex">
								<h5 class="form-control btn">BUSCAR:</h5><input class="search" type="search" name="tbus" placeholder="Buscar Alumno..." >
								<button class="form-control btn" type="submit"><span class="fa fa-search"> Por Codigo o Nombre</span></button>
								
							</form>
						</div>
						
					</div>
<?php  
$query = "SELECT * FROM bdcontrolcomedor.alumno where concat(CodAlumno,NombreAlum,ApepaAlum,ApemaAlum)  like '%$bus%';";
	$resultado = $mysqli->query($query);

?>
	<div class="contact py-1" id="contact">
		<div class="container pb-xl-4 pb-lg-2">
			
		<table border="1" class=""><tr bgcolor="00ffff"><td>CODIGO</td><td>APELLIDOS Y NOMBRES</td><td>GENERAR REPORTE</td></tr>
		<?php while($row = $resultado->fetch_array())
	{ ?>
		<tr>
			<td><?php echo $row[0];?></td>
			<td><?php echo $row[2].' '.$row[3].' '.$row[1]; ?></td>
		<td align="center" ><a href="pdfrgasto.php?cod=<?php echo $row[0];?>"target="_blank" ><img src="images/detalle.png"width="30" height="30"></a></td>
		</tr>
		<?php } ?>
	</table>
				
				
							
					
					</div>
					<!-- //contact form grid ends here -->
				</div>
			
			
		

</center>
	
	<!-- //contact-->

</body>

</html>