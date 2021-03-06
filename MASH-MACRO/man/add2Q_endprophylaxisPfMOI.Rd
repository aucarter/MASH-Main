% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/PATHOGEN-PfMOI-Methods.R
\name{add2Q_endprophylaxisPfMOI}
\alias{add2Q_endprophylaxisPfMOI}
\title{PfMOI \code{Human} Event: Add PfMOI End of Chemoprophylaxis Event to Event Queue}
\usage{
add2Q_endprophylaxisPfMOI(tEvent, PAR = NULL)
}
\arguments{
\item{tEvent}{time of event}

\item{PAR}{\code{NULL}}
}
\description{
Add PfMOI end of chemoprophylaxis event to the event queue.
This method is called from \code{\link{treatPfMOI}}
This method adds event \code{\link{event_endprophylaxisPfMOI}} to the event queue.
This method is bound to \code{Human$add2Q_endprophylaxisPfMOI()}
\itemize{
\item tEvent: treatment time is calculated as tSusceptible = tEvent + \code{\link{PfMOI_ttSusceptiblePf}}
}
}
