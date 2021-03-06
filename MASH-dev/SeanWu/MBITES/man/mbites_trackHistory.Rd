% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/MBITES-Logging.R
\name{mbites_trackHistory}
\alias{mbites_trackHistory}
\title{MBITES: Track History}
\usage{
mbites_trackHistory()
}
\description{
At the end of each bout (\code{\link{mbites_oneBout}}), track the mosquito's history. If the mosquito
is dead, write out the history to a JSON-formatted file
\itemize{
\item This method is bound to \code{Mosquito_Female$trackHistory}
}
}
