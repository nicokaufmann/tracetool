#include "filter.h"

#include <string>

using namespace Tracelib;
using namespace std;

VerbosityFilter::VerbosityFilter()
    : m_maxVerbosity( 1 )
{
}

void VerbosityFilter::setMaximumVerbosity( unsigned short verbosity )
{
    m_maxVerbosity = verbosity;
}

bool VerbosityFilter::acceptsEntry( unsigned short verbosity, const char *sourceFile, unsigned int lineno, const char *functionName )
{
    return verbosity <= m_maxVerbosity;
}

static bool startsWith( const string &a, const string &b )
{
    return b.size() <= a.size() && a.substr( 0, b.size() ) == b;
}

SourceFilePathFilter::SourceFilePathFilter()
{
}

void SourceFilePathFilter::addAcceptablePath( const string &path )
{
    m_acceptablePaths.push_back( path );
}

bool SourceFilePathFilter::acceptsEntry( unsigned short verbosity, const char *sourceFile, unsigned int lineno, const char *functionName )
{
    vector<string>::const_iterator it, end = m_acceptablePaths.end();
    for ( it = m_acceptablePaths.begin(); it != end; ++it ) {
        if ( startsWith( sourceFile, *it ) ) { // XXX Implement regex matching
            return true;
        }
    }
    return false;
}
