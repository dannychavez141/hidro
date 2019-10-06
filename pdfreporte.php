<?php
	include 'plantilla/plantillareporte.php';
	require 'control/conexion.php';

	$isla=$_POST['isla'];
	$ini=$_POST['ini'];
	$fin=$_POST['fin'];
	
	

 function estado($valor)
{
	if ($valor==0) {
		$msj="CERRADO";
		
	} else{
		$msj="ABIERTO";

}
	return $msj;

}
function nisla($valor)
{
	if ($valor==1) {
		$msj="ISLA 1";
		
	} else
	if ($valor==2) {
		$msj="ISLA 2";
		
	} else
	if ($valor==3) {
		$msj="ISLA 3";
		
	} else{
		$msj="TODAS LAS ISLAS";

}

	return $msj;

}
	$pdf = new PDF();
	$pdf->AliasNbPages();
	$pdf->AddPage();


	$pdf->SetX(30);
	$pdf->SetFont('Arial','BU',11);
	$pdf->Cell(50,5, 'DATOS DEL REPORTE',1,1,'C');
	$pdf->SetFillColor(232,232,232);
	$pdf->SetFont('Arial','B',9);
	$pdf->SetX(30);
	$pdf->Cell(50,6,'NUMERO DE ISLA',1,0,'C',1);
	$pdf->Cell(75,6,utf8_decode(nisla($isla)),1,1,'C');
	$pdf->SetX(30);
	$pdf->Cell(50,6,'FECHA INICIO',1,0,'C',1);
	$pdf->Cell(75,6,utf8_decode($ini),1,1,'C');
	$pdf->SetX(30);
	$pdf->Cell(50,6,'FECHA FIN:',1,0,'C',1);
	$pdf->Cell(75,6,utf8_decode($fin),1,1,'C');
	

	if ($isla==0) {
	$query = "SELECT * FROM reporte where fecha<='$fin' and fecha>='$ini' order by fecha desc limit 100";	
	}
if ($isla==1) {
	$query = "SELECT * FROM reporte where hsuelo1=1 and fecha<='$fin' and fecha>='$ini' order by fecha desc limit 100";	
	}
	if ($isla==2) {
	$query = "SELECT * FROM reporte where hsuelo2=1 and fecha<='$fin' and fecha>='$ini' order by fecha desc limit 100";	
	}
	if ($isla==3) {
	$query = "SELECT * FROM reporte where hsuelo3=1 and fecha<='$fin' and fecha>='$ini' order by fecha desc limit 100";	
	}


	
	$pdf->Ln(5);
	$pdf->SetX(30);
	$pdf->SetFont('Arial','BU',11);
	$pdf->Cell(150,5, 'INCIDENCIAS REGISTRADAS',1,1,'C');
	$pdf->SetFillColor(232,232,232);
	$pdf->SetFont('Arial','B',9);
	$pdf->Ln(5);
	$pdf->SetX(15);
	$pdf->Cell(10,6,utf8_decode('N°'),1,0,'C',1);
	$pdf->Cell(50,6,'FECHA',1,0,'C',1);
	$pdf->Cell(50,6,'TEMPERATURA/HUMEDAD',1,0,'C',1);
	$pdf->Cell(20,6,'LLAVE1',1,0,'C',1);
	$pdf->Cell(20,6,'LLAVE2',1,0,'C',1);
	$pdf->Cell(20,6,'LLAVE3',1,1,'C',1);
$resultado = $mysqli->query($query);
while($row = $resultado->fetch_array())
	{
	   $pdf->SetX(15);
		$pdf->Cell(10,6,$row[0],1,0,'C');
		$pdf->Cell(50,6,utf8_decode($row[6]),1,0,'C');
		$pdf->Cell(50,6,utf8_decode($row[2]."°C / ".$row[1]."%"),1,0,'C');
		if ($row[3]==1) {
			$pdf->SetTextColor(0,0,255);
		}else{
           $pdf->SetTextColor(255,0,0);
		}

		$pdf->Cell(20,6,utf8_decode(estado($row[3])),1,0,'C');
if ($row[4]==1) {
			$pdf->SetTextColor(0,0,255);
		}else{
           $pdf->SetTextColor(255,0,0);
		}
		$pdf->Cell(20,6,utf8_decode(estado($row[4])),1,0,'C');
if ($row[5]==1) {
			$pdf->SetTextColor(0,0,255);
		}else{
           $pdf->SetTextColor(255,0,0);
		}
		$pdf->Cell(20,6,utf8_decode(estado($row[5])),1,1,'C');
	
	 $pdf->SetTextColor(0,0,0);
	}

	$pdf->Ln(20);
	$pdf->Cell(200,6,'_______________________                     	______________________',0,0,'C',0);
$pdf->Ln(6);
	$pdf->Cell(198,6,'Firma Encargado                                        Firma Delegado',0,0,'C',0);
	$modo="I";
    $nombre_archivo="Lista_Reporte.pdf";
    $pdf->Output($nombre_archivo,$modo); 
?>