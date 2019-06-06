-- phpMyAdmin SQL Dump
-- version 4.2.11
-- http://www.phpmyadmin.net
--
-- Servidor: 127.0.0.1
-- Tiempo de generación: 06-06-2019 a las 18:36:47
-- Versión del servidor: 5.5.40
-- Versión de PHP: 5.5.19

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Base de datos: `hidroponia`
--
CREATE DATABASE IF NOT EXISTS `hidroponia` DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci;
USE `hidroponia`;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `horas`
--

DROP TABLE IF EXISTS `horas`;
CREATE TABLE IF NOT EXISTS `horas` (
`idhoras` int(11) NOT NULL,
  `descr` varchar(45) DEFAULT NULL,
  `hora` time DEFAULT NULL
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8;

--
-- Volcado de datos para la tabla `horas`
--

INSERT INTO `horas` (`idhoras`, `descr`, `hora`) VALUES
(1, '5am', '05:00:00'),
(2, '6am', '06:00:00'),
(3, '7am', '07:00:00'),
(4, '8am', '08:00:00'),
(5, '5pm', '17:00:00'),
(6, '6pm', '18:00:00'),
(7, '7pm', '19:00:00');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `hora_riego`
--

DROP TABLE IF EXISTS `hora_riego`;
CREATE TABLE IF NOT EXISTS `hora_riego` (
  `idhoras` int(11) NOT NULL,
  `idtplanta` int(11) NOT NULL,
  `duracion` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `insumos`
--

DROP TABLE IF EXISTS `insumos`;
CREATE TABLE IF NOT EXISTS `insumos` (
`idinsumos` int(11) NOT NULL,
  `descr` varchar(45) DEFAULT NULL
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8;

--
-- Volcado de datos para la tabla `insumos`
--

INSERT INTO `insumos` (`idinsumos`, `descr`) VALUES
(1, 'Abono Universal Generico'),
(2, 'Abono Rosales'),
(3, 'Abono Plantas Verdes'),
(4, 'Abono Citricos'),
(5, 'Abono Hortencias');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `plantas`
--

DROP TABLE IF EXISTS `plantas`;
CREATE TABLE IF NOT EXISTS `plantas` (
`idplantas` int(11) NOT NULL,
  `descr` varchar(45) DEFAULT NULL,
  `idtplanta` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `plantas_insumos`
--

DROP TABLE IF EXISTS `plantas_insumos`;
CREATE TABLE IF NOT EXISTS `plantas_insumos` (
`idplantainsumo` int(11) NOT NULL,
  `idinsumos` int(11) NOT NULL,
  `idtplanta` int(11) NOT NULL,
  `cantidad` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `reporte`
--

DROP TABLE IF EXISTS `reporte`;
CREATE TABLE IF NOT EXISTS `reporte` (
`idreporte` int(11) NOT NULL,
  `hum` double DEFAULT '0',
  `temp` double DEFAULT '0',
  `hsuelo1` double DEFAULT '0',
  `hsuelo2` double DEFAULT '0',
  `hsuelo3` double DEFAULT '0',
  `fecha` datetime DEFAULT NULL
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8;

--
-- Volcado de datos para la tabla `reporte`
--

INSERT INTO `reporte` (`idreporte`, `hum`, `temp`, `hsuelo1`, `hsuelo2`, `hsuelo3`, `fecha`) VALUES
(1, 86, 23, 11, 0, 0, '2019-05-26 02:32:45'),
(2, 87, 24, 11, 0, 0, '2019-05-26 02:32:50'),
(3, 86, 24, 11, 0, 0, '2019-05-26 02:32:56'),
(4, 87, 24, 12, 0, 0, '2019-05-26 02:33:01'),
(5, 87, 24, 14, 0, 0, '2019-05-26 02:33:06'),
(6, 87, 24, 12, 0, 0, '2019-05-26 02:33:12'),
(7, 86, 24, 14, 0, 0, '2019-05-26 02:33:17');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `riego`
--

DROP TABLE IF EXISTS `riego`;
CREATE TABLE IF NOT EXISTS `riego` (
`idriego` int(11) NOT NULL,
  `idplantas` int(11) NOT NULL,
  `idusuario` int(11) NOT NULL,
  `fecha` datetime DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `tplanta`
--

DROP TABLE IF EXISTS `tplanta`;
CREATE TABLE IF NOT EXISTS `tplanta` (
`idtplanta` int(11) NOT NULL,
  `descr` varchar(45) DEFAULT NULL,
  `temp` double DEFAULT NULL,
  `hum` double DEFAULT NULL,
  `triego` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `usuario`
--

DROP TABLE IF EXISTS `usuario`;
CREATE TABLE IF NOT EXISTS `usuario` (
`idusuario` int(11) NOT NULL,
  `nom` varchar(45) DEFAULT NULL,
  `ape` varchar(45) DEFAULT NULL,
  `dni` varchar(45) DEFAULT NULL,
  `pass` varchar(45) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Índices para tablas volcadas
--

--
-- Indices de la tabla `horas`
--
ALTER TABLE `horas`
 ADD PRIMARY KEY (`idhoras`);

--
-- Indices de la tabla `hora_riego`
--
ALTER TABLE `hora_riego`
 ADD PRIMARY KEY (`idhoras`,`idtplanta`), ADD KEY `fk_hora_riego_tplanta1_idx` (`idtplanta`), ADD KEY `fk_hora_riego_horas1_idx` (`idhoras`);

--
-- Indices de la tabla `insumos`
--
ALTER TABLE `insumos`
 ADD PRIMARY KEY (`idinsumos`);

--
-- Indices de la tabla `plantas`
--
ALTER TABLE `plantas`
 ADD PRIMARY KEY (`idplantas`), ADD KEY `fk_plantas_tplanta_idx` (`idtplanta`);

--
-- Indices de la tabla `plantas_insumos`
--
ALTER TABLE `plantas_insumos`
 ADD PRIMARY KEY (`idplantainsumo`), ADD KEY `fk_plantas_has_insumos_insumos1_idx` (`idinsumos`), ADD KEY `fk_plantas_insumos_tplanta1_idx` (`idtplanta`);

--
-- Indices de la tabla `reporte`
--
ALTER TABLE `reporte`
 ADD PRIMARY KEY (`idreporte`);

--
-- Indices de la tabla `riego`
--
ALTER TABLE `riego`
 ADD PRIMARY KEY (`idriego`), ADD KEY `fk_riego_plantas1_idx` (`idplantas`), ADD KEY `fk_riego_usuario1_idx` (`idusuario`);

--
-- Indices de la tabla `tplanta`
--
ALTER TABLE `tplanta`
 ADD PRIMARY KEY (`idtplanta`);

--
-- Indices de la tabla `usuario`
--
ALTER TABLE `usuario`
 ADD PRIMARY KEY (`idusuario`);

--
-- AUTO_INCREMENT de las tablas volcadas
--

--
-- AUTO_INCREMENT de la tabla `horas`
--
ALTER TABLE `horas`
MODIFY `idhoras` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=8;
--
-- AUTO_INCREMENT de la tabla `insumos`
--
ALTER TABLE `insumos`
MODIFY `idinsumos` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=6;
--
-- AUTO_INCREMENT de la tabla `plantas`
--
ALTER TABLE `plantas`
MODIFY `idplantas` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT de la tabla `plantas_insumos`
--
ALTER TABLE `plantas_insumos`
MODIFY `idplantainsumo` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT de la tabla `reporte`
--
ALTER TABLE `reporte`
MODIFY `idreporte` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=8;
--
-- AUTO_INCREMENT de la tabla `riego`
--
ALTER TABLE `riego`
MODIFY `idriego` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT de la tabla `tplanta`
--
ALTER TABLE `tplanta`
MODIFY `idtplanta` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT de la tabla `usuario`
--
ALTER TABLE `usuario`
MODIFY `idusuario` int(11) NOT NULL AUTO_INCREMENT;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
