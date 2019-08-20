Each URI begins with a scheme name that refers to a specification for
   assigning identifiers within that scheme.  As such, the URI syntax is
   a federated and extensible naming system wherein each scheme's
   specification may further restrict the syntax and semantics of
   identifiers using that scheme.

   Scheme names consist of a sequence of characters beginning with a
   letter and followed by any combination of letters, digits, plus
   ("+"), period ("."), or hyphen ("-").  Although schemes are case-
   insensitive, the canonical form is lowercase and documents that
   specify schemes must do so with lowercase letters.  An implementation
   should accept uppercase letters as equivalent to lowercase in scheme
   names (e.g., allow "HTTP" as well as "http") for the sake of
   robustness but should only produce lowercase scheme names for
   consistency.

      scheme      = ALPHA *( ALPHA / DIGIT / "+" / "-" / "." )

   Individual schemes are not specified by this document.  The process
   for registration of new URI schemes is defined separately by [BCP35].
   The scheme registry maintains the mapping between scheme names and
   their specifications.  Advice for designers of new URI schemes can be
   found in [RFC2718].  URI scheme specifications must define their own
   syntax so that all strings matching their scheme-specific syntax will
   also match the <absolute-URI> grammar, as described in Section 4.3.

   When presented with a URI that violates one or more scheme-specific
   restrictions, the scheme-specific resolution process should flag the
   reference as an error rather than ignore the unused parts; doing so
   reduces the number of equivalent URIs and helps detect abuses of the
   generic syntax, which might indicate that the URI has been
   constructed to mislead the user (Section 7.6).
