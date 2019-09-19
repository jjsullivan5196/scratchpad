{-# LANGUAGE DeriveGeneric, DeriveAnyClass #-}
module Lib
    ( someFunc
    ) where

import GHC.Generics
import Data.Aeson
import Data.ByteString.Lazy.UTF8

data City = City {
  name :: String,
  population :: Int }
  deriving(Generic, ToJSON, FromJSON)

cityjson = toString . encode . toJSON $ City "Los Angeles" 3000000

someFunc :: IO ()
someFunc = putStrLn cityjson
