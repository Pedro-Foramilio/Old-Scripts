{-# LANGUAGE CPP #-}
{-# LANGUAGE NoRebindableSyntax #-}
{-# OPTIONS_GHC -fno-warn-missing-import-lists #-}
module Paths_projeto_simples (
    version,
    getBinDir, getLibDir, getDynLibDir, getDataDir, getLibexecDir,
    getDataFileName, getSysconfDir
  ) where

import qualified Control.Exception as Exception
import Data.Version (Version(..))
import System.Environment (getEnv)
import Prelude

#if defined(VERSION_base)

#if MIN_VERSION_base(4,0,0)
catchIO :: IO a -> (Exception.IOException -> IO a) -> IO a
#else
catchIO :: IO a -> (Exception.Exception -> IO a) -> IO a
#endif

#else
catchIO :: IO a -> (Exception.IOException -> IO a) -> IO a
#endif
catchIO = Exception.catch

version :: Version
version = Version [0,1,0,0] []
bindir, libdir, dynlibdir, datadir, libexecdir, sysconfdir :: FilePath

bindir     = "C:\\Users\\phcfo\\OneDrive\\Documentos\\Repositorios\\Old-Scripts\\haskell\\projetoTesteBuild\\projeto-simples\\.stack-work\\install\\9bd76dae\\bin"
libdir     = "C:\\Users\\phcfo\\OneDrive\\Documentos\\Repositorios\\Old-Scripts\\haskell\\projetoTesteBuild\\projeto-simples\\.stack-work\\install\\9bd76dae\\lib\\x86_64-windows-ghc-8.10.7\\projeto-simples-0.1.0.0-GvkkEEldFSo1VckS3AJCN4-projeto-simples"
dynlibdir  = "C:\\Users\\phcfo\\OneDrive\\Documentos\\Repositorios\\Old-Scripts\\haskell\\projetoTesteBuild\\projeto-simples\\.stack-work\\install\\9bd76dae\\lib\\x86_64-windows-ghc-8.10.7"
datadir    = "C:\\Users\\phcfo\\OneDrive\\Documentos\\Repositorios\\Old-Scripts\\haskell\\projetoTesteBuild\\projeto-simples\\.stack-work\\install\\9bd76dae\\share\\x86_64-windows-ghc-8.10.7\\projeto-simples-0.1.0.0"
libexecdir = "C:\\Users\\phcfo\\OneDrive\\Documentos\\Repositorios\\Old-Scripts\\haskell\\projetoTesteBuild\\projeto-simples\\.stack-work\\install\\9bd76dae\\libexec\\x86_64-windows-ghc-8.10.7\\projeto-simples-0.1.0.0"
sysconfdir = "C:\\Users\\phcfo\\OneDrive\\Documentos\\Repositorios\\Old-Scripts\\haskell\\projetoTesteBuild\\projeto-simples\\.stack-work\\install\\9bd76dae\\etc"

getBinDir, getLibDir, getDynLibDir, getDataDir, getLibexecDir, getSysconfDir :: IO FilePath
getBinDir = catchIO (getEnv "projeto_simples_bindir") (\_ -> return bindir)
getLibDir = catchIO (getEnv "projeto_simples_libdir") (\_ -> return libdir)
getDynLibDir = catchIO (getEnv "projeto_simples_dynlibdir") (\_ -> return dynlibdir)
getDataDir = catchIO (getEnv "projeto_simples_datadir") (\_ -> return datadir)
getLibexecDir = catchIO (getEnv "projeto_simples_libexecdir") (\_ -> return libexecdir)
getSysconfDir = catchIO (getEnv "projeto_simples_sysconfdir") (\_ -> return sysconfdir)

getDataFileName :: FilePath -> IO FilePath
getDataFileName name = do
  dir <- getDataDir
  return (dir ++ "\\" ++ name)
