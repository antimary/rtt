<?
 #############################################################################
 # IMDBPHP                              (c) Giorgos Giagas & Itzchak Rehberg #
 # written by Giorgos Giagas                                                 #
 # extended & maintained by Itzchak Rehberg <izzysoft AT qumran DOT org>     #
 # http://www.izzysoft.de/                                                   #
 # ------------------------------------------------------------------------- #
 # Checking class imdb_nowplaying                                            #
 # ------------------------------------------------------------------------- #
 # This program is free software; you can redistribute and/or modify it      #
 # under the terms of the GNU General Public License (see doc/LICENSE)       #
 #############################################################################

 /* $Id: imdb_nowplaying.inc 253 2009-10-11 21:54:15Z izzy $ */

require_once ("imdb_nowplaying.class.php");
require_once(dirname(__FILE__)."/helpers.inc");

$imdb->cachedir = "../cache";
switch ($_REQUEST["cache"]) {
  case "false":
  case "off"  :
  case "0"    : $imdb->usecache = 0; $imdb->storecache = 0;
                comment("Caching turned off.");
                break;
  case "true" :
  case "on"   :
  case 1      : $imdb->usecache = 1; $imdb->storecache = 1;
                comment("Caching turned on.");
                break;
}

$imdb = new imdb_nowplaying();

headline("Class imdb_nowplaying (Revision ".$imdb->revision.")","imdb_nowplaying");

raw(" <LI>method getNowPlayingMovies(): ");
$res  = $imdb->getNowPlayingMovies();
if (empty($res)||empty($res[0])) fail("getNowPlayingMovies");
else pass();
raw("</LI>\n");
++$GLOBALS["methods"];

raw("<hr>\n");
flush();
?>