<?php
	include 'plantilla.php';
	require 'conexion.php';
$cod = $_GET['cod'];

	$query = "select * from(SELECT g.CodAlumno,g.Fecha as fecha,g.Hora as hora,concat('-',g.Monto) as monto,g.idTipoGasto,tg.Descr  as tipo FROM bdcontrolcomedor.controlgasto g join tipogasto tg on g.idTipoGasto=tg.idTipoGasto
 union 
SELECT r.CodAlumno, r. Fecha as fecha,r.Hora as hora,r.Monto  as monto,r.idUsuario, concat(NombreUsu,ApepaUsu,ApemaUsu) as tipo FROM bdcontrolcomedor.controlrecarga r join usuario u on r.idUsuario=u.idUsuario ) t where CodAlumno='$cod' order by  t.hora and t.fecha ;";
     $sql = "SELECT * FROM bdcontrolcomedor.alumno where CodAlumno=$cod;";
	$rs = $mysqli->query($sql);
	while($raw = $rs->fetch_array())
	{
 $alu=utf8_decode($raw[2].' '.$raw[3].' '.$raw[1]); 
 $sald=$raw[5];
	}



	$resultado = $mysqli->query($query);
	
	$pdf = new PDF();
	$pdf->AliasNbPages();
	$pdf->AddPage();
	$pdf->Ln(10);
	$pdf->SetX(53);
	$pdf->Cell(40,6, 'Codigo:'.$cod,0,1,'C');
	$pdf->SetX(55);
	$pdf->Cell(53,6, 'Apellidos y Nombres:'.$alu,0,1,'C');
	$pdf->SetX(55);
	$pdf->Cell(53,6, 'Saldo Actual: S/ '.$sald.'.00',0,1,'C');
	$pdf->Ln(10);
	$pdf->SetFillColor(232,232,232);
	$pdf->SetX(35);
	$pdf->SetFont('Arial','B',12);
	$pdf->Cell(25,6,'CODIGO',1,0,'C',1);
	$pdf->Cell(25,6,'FECHA',1,0,'C',1);
	$pdf->Cell(25,6,'HORA',1,0,'C',1);
	$pdf->Cell(25,6,'MONTO S/',1,0,'C',1);
	$pdf->Cell(50,6,'GASTO/RECARGA',1,1,'C',1);
	$pdf->SetFont('Arial','',10);
	while($row = $resultado->fetch_array())
	{$pdf->SetX(35);
		$pdf->Cell(25,6,$row[0],1,0,'C');
		$pdf->Cell(25,6,utf8_decode($row[1]),1,0,'C');
		$pdf->Cell(25,6,utf8_decode($row[2]),1,0,'C');
		$pdf->Cell(25,6,utf8_decode($row[3]).'.00',1,0,'C');
		$pdf->Cell(50,6,utf8_decode($row[5]),1,1,'C');
	}
	$pdf->Output();
?>